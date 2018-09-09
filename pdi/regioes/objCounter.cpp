#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// Estrutura para o rótulo de um obejto
struct label {
    CvPoint p;
    Vec3b color;
};

void removeBorderObj(Mat &img) {
    int width = img.size().width, height = img.size().height;

    label l;
    l.color = Vec3b(0, 0, 0);

    for(int i = 0; i < height; i++) {
        // Verific a primeira coluna
        if(img.at<Vec3b>(i, 0) == Vec3b(255, 255, 255)){
            l.p.x = 0;
            l.p.y = i;

            floodFill(img, l.p, l.color);            
        }
        
        // Verifica a ultima coluna
        if(img.at<Vec3b>(i, img.cols - 1) == Vec3b(255, 255, 255)){
            l.p.x = img.cols - 1;
            l.p.y = i;

            floodFill(img, l.p, l.color);  
        }
    }

    for(int j = 0; j < width; j++) {
        // Verific a primeira linha
        if(img.at<Vec3b>(0, j) == Vec3b(255, 255, 255)){
            l.p.x = j;
            l.p.y = 0;

            floodFill(img, l.p, l.color);            
        }
        
        // Verifica a ultima linha
        if(img.at<Vec3b>(img.rows - 1, j) == Vec3b(255, 255, 255)){
            l.p.x = j;
            l.p.y = img.rows - 1;

            floodFill(img, l.p, l.color);  
        }
    }
}

int labelImg(Mat &img) {
    int width = img.size().width, 
    height = img.size().height,
    nObj = 0;
    
    label l;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(img.at<Vec3b>(i, j) == Vec3b(255, 255, 255)){
                // Semete de um objeto foi encontrada
                nObj++;
                // Salva a cordenada da semente
                l.p.x = j;
                l.p.y = i;
                //Controi uma cor BGR com base no numero do objeto
                l.color = Vec3b(
                    nObj%255, 
                    (nObj/255)%255, 
                    nObj/(255*255)
                );
                floodFill(img, l.p, Scalar(l.color));
            }
        }
    }

    return nObj;
}

void changeBg(Mat &img) {
    label l;
    
    // Pixel para o inicio do floodfill
    l.p = CvPoint(0, 0);

    // Novo Bg
    l.color = Vec3b(255, 255, 255);

    // Floodfill the Bg
    floodFill(img, l.p, l.color);
}

int countHoles(Mat &img) {
    int width = img.size().width, 
    height = img.size().height,
    nObj = 0;

    label l;
    l.color = Vec3b(255, 255, 255);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(img.at<Vec3b>(i, j) == Vec3b(0, 0, 0)){
                // Semete de um objeto foi encontrada
                nObj++;
                // Salva a cordenada da semente
                l.p = CvPoint(j, i); 
                
                floodFill(img, l.p, l.color);
            }
        }
    }

    return nObj;
}

int main(int argc, char** argv) {
    if(argc < 2) {
        cout << "Argumentos faltando!\nUso: ./regions <caminho_para_imagem>\n";
        return -1;
    }
    
    Mat img, aux;
    img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    if(!img.data){
        cout << "Error ao abir " << argv[1] << endl;
        return -1;
    }
    aux = img.clone();
    
    // Remove os objetos que tocam a borda da imagem
    removeBorderObj(aux);

    // Rotula todos os objetos
    int nObj = labelImg(aux);

    // Preenche o fundo com outra cor
    changeBg(aux);

    // Contar os objetor com buraco
    int nObjHole = countHoles(aux);

    cout << "\nObjetos sem buraco(s): " << nObj - nObjHole 
    << "\n\nObjetos com buraco(s): " << nObjHole << "\n\n";

    imshow("Original Image", img);
    imshow("Fully Labelled Image", aux);
    waitKey();    

    return 0;
}