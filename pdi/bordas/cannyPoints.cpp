#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

#define RAIO 3

using namespace std;
using namespace cv;

int canny_slider = 15;
int canny_slider_max = 200;

char TrackbarName[50];

Mat image, edges, points;

void getPointillisticImage() {
    // Cria variaveis para as dimensoes da imagem
    int height = image.size().height, width = image.size().width;

    // Cria as matrizes para as bordas da imagem e para a imagem de pontos 
    points = Mat(height, width, CV_8UC3, Scalar(255, 255, 255));

    Canny(image, edges, canny_slider, 3 * canny_slider);

    // Percorre a matriz com as bordas e preenche um vetor com as coordenadas
    // dos pixels de valor 255
    vector<vector<int>> edgesCoordinates;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(edges.at<uchar>(i, j) == 255) {
                edgesCoordinates.push_back({i, j});
            }
        }
    }

    // Embaralha as coordenas onde os circulos serão desenhados 
    // para aumentar a autenticidade do resultado 
    random_shuffle(edgesCoordinates.begin(), edgesCoordinates.end());

    // Percorre as coordenadas e desenha em uma nova matrix os pontos 
    // com cor igual a cor da imagem na posição correspodente
    for(auto coordinate : edgesCoordinates) {
        Vec3b color = image.at<Vec3b>(coordinate[0], coordinate[1]);
        
        circle(points, Point(coordinate[1], coordinate[0]), RAIO, color, -1, CV_AA);
    }
    
}

void on_trackbar_canny(int, void*){
    getPointillisticImage();

    imshow("Canny Points", points);
}

int main(int argc, char**argv) {
    if(argc < 2) {
        cout << "Argumentos faltando!\nUso: ./cannyPoints <caminho_para_imagem>\n";
        return -1;
    }
    
    // Carrega a imagem
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if(!image.data) {
        cout << "Error ao carregar a imagem!\n";
        return -1;
    }

    sprintf(TrackbarName, "Threshold", canny_slider_max);

    namedWindow("Canny Points", WINDOW_KEEPRATIO);

    createTrackbar(
        TrackbarName, 
        "Canny Points",
        &canny_slider,
        canny_slider_max,
        on_trackbar_canny
    );

    on_trackbar_canny(canny_slider, 0);

    waitKey(0);

    return 0;
}