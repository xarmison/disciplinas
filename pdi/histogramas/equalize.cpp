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

    while(true) {
        Mat img;
        cap >> img;

        // Inverte a imagem
        flip(img, img, 1);

        // Tranforma a imagem capturada para grayscale
        cvtColor(img, img, CV_BGR2GRAY);

        // Equaliza o histograma
        equalizeHist(img, img);

        imshow("Equalized Histogram", img);
        if(waitKey(30) >= 0) break;
    }


    return 0;
}