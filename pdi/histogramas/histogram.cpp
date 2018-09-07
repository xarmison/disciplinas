#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    VideoCapture cap;
    cap.open(0);
    if(!cap.isOpened()) {
        cout << "Erro ao acessar a camera!\n";
        return -1;
    }

    // Calcula a largura e altura dos framas capturados
    int width = cap.get(CV_CAP_PROP_FRAME_WIDTH),
        height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

    cout << "Width: " << width
        << "Height: " << height;

    // Cria uma matriz para cada canal de cor para armezar os histogramas
    Mat histR, histG, histB;
    int nbins = 64, histWidth = nbins, histHeight = nbins/2;

    Mat histImgR(histHeight, histWidth, CV_8UC3, Scalar(0,0,0));
    Mat histImgG(histHeight, histWidth, CV_8UC3, Scalar(0,0,0));
    Mat histImgB(histHeight, histWidth, CV_8UC3, Scalar(0,0,0));

    // Define o range do histograma
    float range[] = {0, 256};
    const float *histRange = { range };

    while(true) {
        Mat img;
        cap >> img;

        // Inverte a imagem
        flip(img, img, 1);

        // Separa os canais de cor
        vector<Mat> channels;
        split(img, channels);

        // Calcula o histograma de cada cor
        calcHist(&channels[0], 1, 0, Mat(), histR, 1, &nbins, &histRange);
        calcHist(&channels[1], 1, 0, Mat(), histG, 1, &nbins, &histRange);
        calcHist(&channels[2], 1, 0, Mat(), histB, 1, &nbins, &histRange);

        // Normaliza os histogramas
        normalize(histR, histR, 0, histImgR.rows, NORM_MINMAX, -1, Mat());
        normalize(histG, histG, 0, histImgG.rows, NORM_MINMAX, -1, Mat());
        normalize(histB, histB, 0, histImgB.rows, NORM_MINMAX, -1, Mat());

        // Seta Bg para o gráfico dos histogramas
        histImgR.setTo(Scalar(0));
        histImgG.setTo(Scalar(0));
        histImgB.setTo(Scalar(0));

        // Desenha o histograma com a quantidade de bins desejada
        for(int i = 0; i < nbins; i++){
            line(
                histImgR, 
                Point(i, histHeight), 
                Point(i, histHeight-cvRound(histR.at<float>(i))),
                Scalar(0, 0, 255),
                1, 8, 0
            );
            line(
                histImgG, 
                Point(i, histHeight), 
                Point(i, histHeight-cvRound(histR.at<float>(i))),
                Scalar(0, 255, 0),
                1, 8, 0
            );
            line(
                histImgB, 
                Point(i, histHeight), 
                Point(i, histHeight-cvRound(histR.at<float>(i))),
                Scalar(255, 0, 0),
                1, 8, 0
            );
        }
        histImgR.copyTo(img(Rect(0, 0            ,nbins, histHeight)));
        histImgG.copyTo(img(Rect(0, histHeight   ,nbins, histHeight)));
        histImgB.copyTo(img(Rect(0, 2*histHeight ,nbins, histHeight)));

        imshow("Histogram", img);
        if(waitKey(30) >= 0) break;
    }


    return 0;
}