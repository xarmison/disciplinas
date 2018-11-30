#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main( int argc, char** argv ){
  if(argc != 3) {
    cout << "Argumentos faltando!\nUso: ./kmeans <caminho_para_imagem> <numero_de_clusters>\n";
	  return -1;
  }

  Mat img = imread( argv[1], CV_LOAD_IMAGE_COLOR);
  
  if(!img.data) {
    cout << "Error ao carregar a imagem!\n";
    return -1;
  }

  int nClusters = stoi(argv[2]);
  Mat rotulos;
  int nRodadas = 5;
  Mat centros;

  Mat samples(img.rows * img.cols, 3, CV_32F);

  for( int y = 0; y < img.rows; y++ ){
    for( int x = 0; x < img.cols; x++ ){
      for( int z = 0; z < 3; z++){
        samples.at<float>(y + x*img.rows, z) = img.at<Vec3b>(y,x)[z];
	  }
	}
  }
  
  kmeans(samples,
		 nClusters,
		 rotulos,
		 TermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 10000, 0.0001),
		 nRodadas,
		 KMEANS_PP_CENTERS,
		 centros );


  Mat rotulada( img.size(), img.type() );
  for( int y = 0; y < img.rows; y++ ){
    for( int x = 0; x < img.cols; x++ ){ 
      int indice = rotulos.at<int>(y + x*img.rows,0);
      rotulada.at<Vec3b>(y,x)[0] = (uchar) centros.at<float>(indice, 0);
      rotulada.at<Vec3b>(y,x)[1] = (uchar) centros.at<float>(indice, 1);
      rotulada.at<Vec3b>(y,x)[2] = (uchar) centros.at<float>(indice, 2);
    }
  }
  namedWindow("Original Image", WINDOW_KEEPRATIO);
  namedWindow("Clustered Image", WINDOW_KEEPRATIO);
  imshow("Original Image", img);
  imshow("Clustered Image", rotulada);
  waitKey( 0 );
}
