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

    cout << "Width: " << width << endl
        << "Height: " << height << endl;

    Mat previousHist, currentHist;
    int nbins = 64;

    // Define o range do histograma
    float range[] = {0, 256};
    const float *histRange = { range };

    Mat img;
    cap >> img;
    flip(img, img, 1);
    cvtColor(img, img, CV_BGR2GRAY);
    calcHist(&img, 1, 0, Mat(), previousHist, 1, &nbins, &histRange);
    normalize(previousHist, previousHist, 0, previousHist.rows, NORM_MINMAX, -1, Mat());

    // Threshold para alertar movimento
    double threshold = 50;

    while(true) {
        Mat img;
        cap >> img;

        // Inverte a imagem
        flip(img, img, 1);

        // Tranforma a imagem capturada para grayscale
        cvtColor(img, img, CV_BGR2GRAY);
        
        // Calcula o histograma
        calcHist(&img, 1, 0, Mat(), currentHist, 1, &nbins, &histRange);

        // Normaliza o histograma 
        normalize(currentHist, currentHist, 0, currentHist.rows, NORM_MINMAX, -1, Mat());

        double correlation = compareHist(currentHist, previousHist, 1);

        if ((correlation - threshold)  > threshold) {
            cout << "\n\n\n\n***Atenção***\nMovimento Detectado\n" << endl;
        } 


        currentHist.copyTo(previousHist);

        imshow("Motion Detector", img);
        if(waitKey(30) >= 0) break;
    }


    return 0;
}