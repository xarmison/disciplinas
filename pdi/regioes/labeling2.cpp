/*
    A solução proposta por esse programa para o problema da limitação
    de rótulos é rotular os objetos encontrados com uma cor RGB ao 
    invés de um ton de cinza.
*/
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// Estrutura para o rótulo de um obejto
struct label {
    CvPoint p;
    Vec3b color;
};

int main(int argc, char** argv) {
    Mat img;
    img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    if(!img.data){
        cout << "Error ao abir " << argv[1] << endl;
        return -1;
    }
    int width = img.size().width, height = img.size().height;

    // Busca os objetos
    int nObj = 0;
    label l;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(img.at<Vec3b>(i, j) == Vec3b(255, 255, 255)){
                // Semete de um objeto foi encontrada
                nObj++;
                // Salva a cordenada da semente
                l.p = CvPoint(j, i); 
                //Controi uma cor BGR com base no numero do objeto
                l.color = Vec3b(
                    nObj%255, 
                    (nObj/255)%255, 
                    nObj/(255*255)
                );
                floodFill(img, l.p, l.color);
            }
        }
    }

    imshow("Labelled img", img);
    imwrite("imgs/lablled_img_rgb.png", img);
    waitKey();

    return 0;
}