#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat image;
  Vec3b val;

  image = imread("../imgs/bolhas.png",CV_LOAD_IMAGE_GRAYSCALE);

  if(!image.data){
    cout << "Erro ao abrir a imagem\n";
    return -1;
  }

  namedWindow("Image",WINDOW_AUTOSIZE);

  for(int i = 200;i < 210; i++) {
    for(int j = 10;j < 200; j++) {
      image.at<uchar>(i,j) = 0;
    }
  }
  
  imshow("Image", image);  
  waitKey();

  image= imread("../imgs/bolhas.png",CV_LOAD_IMAGE_COLOR);

  val[0] = 66;  //B
  val[1] = 131; //G
  val[2] = 244; //R
  
  for(int i = 200;i < 210; i++) {
    for(int j = 10;j < 200; j++) {
      image.at<Vec3b>(i,j)=val;
    }
  }

  imshow("Image", image);  
  waitKey();
  return 0;
}
