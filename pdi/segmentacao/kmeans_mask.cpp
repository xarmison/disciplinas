#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main( int argc, char** argv ) {
    
    if(argc != 3) {
        cout << "Argumentos faltando!\nUso: ./kmeans <caminho_para_imagem> <numero_de_clusters>\n";
        return -1;
    }

    Mat img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    
    if(!img.data) {
        cout << "Error ao carregar a imagem!\n";
        return -1;
    }

    int nClusters = stoi(argv[2]), nRodadas = 5;
    Mat rotulos, centros;
    Mat samples(img.rows * img.cols, 3, CV_32F);

    for( int y = 0; y < img.rows; y++ ) {
        for( int x = 0; x < img.cols; x++ ) {
            for( int z = 0; z < 3; z++) {
                samples.at<float>(y + x*img.rows, z) = img.at<Vec3b>(y,x)[z];
            }
        }
    }
    
    kmeans(
        samples,
        nClusters,
        rotulos,
        TermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 10000, 0.0001),
        nRodadas,
        KMEANS_PP_CENTERS,
        centros
    );

    Mat rotulada(img.size(), img.type());

    for( int y = 0; y < img.rows; y++ ) {
        for( int x = 0; x < img.cols; x++ ) {  
            int indice = rotulos.at<int>(y + x*img.rows,0);
            if(indice) {
                rotulada.at<Vec3b>(y, x) = Vec3b(0, 0, 255);
            } else {
                rotulada.at<Vec3b>(y, x) = Vec3b(0, 0, 0);
            }
        }
    }

    Mat kernel = getStructuringElement(
        MORPH_ELLIPSE, 
        Size(9, 9), 
        Point(4, 4)
    );

    dilate(rotulada, rotulada, kernel);

    Mat masked(img.size(), img.type());
    addWeighted(rotulada, 0.2, img, 0.8, 0.0, masked);

    namedWindow("Original Image", WINDOW_KEEPRATIO);
    namedWindow("Clustered Image", WINDOW_KEEPRATIO);
    namedWindow("Masked Image", WINDOW_KEEPRATIO);
    imshow("Original Image", img);
    imshow("Clustered Image", rotulada);
    imshow("Masked Image", masked);

    waitKey(0);
    return 0;
}
