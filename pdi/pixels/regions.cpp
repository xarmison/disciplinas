#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    Mat img = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    
    if(!img.data){
        cout << "Erro ao abrir a imagem\n";
        return -1;
    }

    CvPoint p1, p2;

    cout << "Insira as coordenadas do primeiro ponto: ";
    cin >> p1.x >> p1.y;
    
    cout << "Insira as coordenadas do segundo ponto: ";
    cin >> p2.x >> p2.y;

    if (p1.x > img.cols || p2.x > img.cols) {
        cout << "Coordena x do ponto fora da imgem.\n";
        return -1;
    }else if (p1.y > img.rows || p2.y > img.rows){
        cout << "Coordena y do ponto fora da imgem.\n";
        return -1;   
    }

    imshow("Original Image", img);

    for(int i = p1.y; i <= p2.y; i++) {
        for(int j = p1.x; j <= p2.x; j++) {
            img.at<uchar>(i, j) = 255 - img.at<uchar>(i,j);
        }
    }

    imshow("Inverted Image", img);
    waitKey();
    
    return 0;
}