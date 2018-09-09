#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

vector<Mat> getQuarters(Mat img) {

    int GRID_WIDTH = img.cols / 2;
    int GRID_HEIGHT = img.rows / 2;

    vector<Mat> quarters = {
        img(Rect(0, 0, GRID_WIDTH, GRID_HEIGHT)), 
        img(Rect(0, img.cols / 2, GRID_WIDTH, GRID_HEIGHT)),
        img(Rect(img.rows / 2, 0, GRID_WIDTH, GRID_HEIGHT)),
        img(Rect(img.rows / 2, img.cols / 2, GRID_WIDTH, GRID_HEIGHT))
    }; 

    return quarters;
}

void buildImg(Mat &img, vector<Mat> &quarters) {

    int GRID_WIDTH = quarters[0].cols;
    int GRID_HEIGHT = quarters[0].rows;

    int id[] = {0, 1, 2, 3};

    srand(time(NULL));
    random_shuffle(begin(id), end(id));

    quarters[id[0]].copyTo(img(Rect(0, 0, GRID_WIDTH, GRID_HEIGHT)));
    quarters[id[1]].copyTo(img(Rect(0, img.cols / 2, GRID_WIDTH, GRID_HEIGHT)));
    quarters[id[2]].copyTo(img(Rect(img.rows / 2, 0, GRID_WIDTH, GRID_HEIGHT)));
    quarters[id[3]].copyTo(img(Rect(img.rows / 2, img.cols / 2, GRID_WIDTH, GRID_HEIGHT)));
}

int main(int argc, char** argv) {
    if(argc < 2) {
        cout << "Argumentos faltando!\nUso: ./regions <caminho_para_imagem>\n";
        return -1;
    }

    Mat img = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    
    if(!img.data){
        cout << "Erro ao abrir a imagem\n";
        return -1;
    }

    vector<Mat> original_quarters = getQuarters(img);

    Mat newImg(img.cols, img.rows, CV_8UC1, Scalar(0));

    buildImg(newImg, original_quarters);

    imshow("Original Image", img);
    imshow("Scrambled Image", newImg);

    waitKey();
    return 0;
}