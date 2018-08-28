#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv){
  Mat image;
  int width, height, nobjects = 0;
  
  
  image = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
  if(!image.data){
    cout << "Erro ao carregar a imagem!\n";
    return(-1);
  }

  width = image.size().width;
  height = image.size().height;

  CvPoint p;
  p.x=0;
  p.y=0;

  // busca objetos com buracos presentes
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      if(image.at<uchar>(i,j) == 255){
        // achou um objeto
        nobjects++;
        p.x=j;
        p.y=i;
        floodFill(image, p, nobjects);
      }
	  }
  }

  imshow("Labelled Image", image);
  imwrite("imgs/labelled_img.png", image);
  waitKey();
  
  return 0;
}
