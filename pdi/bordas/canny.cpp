#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int top_slider = 0;
int top_slider_max = 200;

char TrackbarName[50];

Mat image, border;

void on_trackbar_canny(int, void*){
  Canny(image, border, top_slider, 3*top_slider);
  imshow("Canny", border);
}

int main(int argc, char**argv){
  if(argc < 2) {
    cout << "Argumentos faltando!\nUso: ./canny <caminho_para_imagem>\n";
    return -1;
  }

  image = imread(argv[1],CV_LOAD_IMAGE_COLOR);

  if(!image.data) {
    cout << "Error ao carregar a imagem!\n";
    return -1;
  }
  
  sprintf(TrackbarName, "Threshold inferior", top_slider_max);

  namedWindow("Canny", WINDOW_KEEPRATIO);

  createTrackbar(
    TrackbarName, 
    "Canny",
    &top_slider,
    top_slider_max,
    on_trackbar_canny
  );

  on_trackbar_canny(top_slider, 0 );

  waitKey();
  return 0;
}
