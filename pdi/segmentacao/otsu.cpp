#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main( int argc, char** argv ) {
    if(argc != 2) {
        cout << "Argumentos faltando!\nUso: ./otsu <caminho_para_imagem>\n";
        exit(0);
    }

    Mat img = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE);
  
    if(!img.data) {
        cout << "Error ao carregar a imagem!\n";
        exit(0);
    }

    // To hold OTSU thresholded Image
    Mat thres = Mat(img.rows, img.cols, CV_8U);

    threshold(img, thres, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    
    namedWindow("Original Image", WINDOW_KEEPRATIO);
    namedWindow("Clustered Image", WINDOW_KEEPRATIO);

    imshow("Original Image", img);
    imshow("Clustered Image", thres);

    waitKey(0);

    return 0;
}