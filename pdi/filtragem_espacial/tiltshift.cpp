#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>

#define BLUR 20

using namespace cv;
using namespace std;

double alpha, focus, position;

int alpha_slider = 20;
int alpha_slider_max = 99;

int focus_slider = 30;
int focus_slider_max = 100;

int position_slider = 50;
int position_slider_max = 100;

char TrackbarName[50];

Mat img, blurredImg, saturatedImg, desfoque, desfoqueInv, result;
float altReg, d, posVert;

void getBlurredImg() {
	Mat aux1, aux2, step1, step2;
	
    float media[] = { 
        1,1,1,
        1,1,1,
        1,1,1 
    };

	Mat mask(3,3,CV_32F, media), mask1;
	scaleAdd(mask, 1/9.0, Mat::zeros(3,3,CV_32F), mask1);
	swap(mask, mask1);

	aux1 = img.clone();
	aux1.convertTo(step1, CV_32F);

	for(int i = 0; i < BLUR; i++){
    	filter2D(step1, step2, step1.depth(), mask, Point(1,1), 0);
    	step2 = abs(step2);
    	step1 = step2.clone();
	}

	aux2 = step2.clone();
    aux2.convertTo(blurredImg, CV_8U);
}

void increaseSaturation() {
    saturatedImg = img.clone();

  	cvtColor(img, img, CV_RGB2HSV);
	cvtColor(saturatedImg, saturatedImg, CV_RGB2HSV);

	for (int i = 0; i < img.rows ; i++) {
      for(int j = 0; j < img.cols; j++) {
			if(img.at<Vec3b>(i,j)[1] <= 100){
				saturatedImg.at<Vec3b>(i,j)[1] = img.at<Vec3b>(i,j)[1] * 2;
			}
			if(img.at<Vec3b>(i,j)[1] <= 200 && img.at<Vec3b>(i,j)[1] > 100){
				saturatedImg.at<Vec3b>(i,j)[1] = img.at<Vec3b>(i,j)[1] * 1.3;
			}
			if(img.at<Vec3b>(i,j)[1] > 200){
				saturatedImg.at<Vec3b>(i,j)[1] = img.at<Vec3b>(i,j)[1] * 2;
			}
		}
	}

	cvtColor(img, img, CV_HSV2RGB);
	cvtColor(saturatedImg, saturatedImg, CV_HSV2RGB);
}

void multiplicaPonderacao(){
	for (int i = 0; i < img.rows ; i++) {
      for(int j = 0; j < img.cols; j++) {
			saturatedImg.at<Vec3b>(i,j)[0] = (int)((float)saturatedImg.at<Vec3b>(i,j)[0] * ((float)desfoque.at<uchar>(i,j)/255.0));
			saturatedImg.at<Vec3b>(i,j)[1] = (int)((float)saturatedImg.at<Vec3b>(i,j)[1] * ((float)desfoque.at<uchar>(i,j)/255.0));
			saturatedImg.at<Vec3b>(i,j)[2] = (int)((float)saturatedImg.at<Vec3b>(i,j)[2] * ((float)desfoque.at<uchar>(i,j)/255.0));

 			blurredImg.at<Vec3b>(i,j)[0] = (int)((float)blurredImg.at<Vec3b>(i,j)[0] * ((float)desfoqueInv.at<uchar>(i,j)/255.0));
			blurredImg.at<Vec3b>(i,j)[1] = (int)((float)blurredImg.at<Vec3b>(i,j)[1] * ((float)desfoqueInv.at<uchar>(i,j)/255.0));
			blurredImg.at<Vec3b>(i,j)[2] = (int)((float)blurredImg.at<Vec3b>(i,j)[2] * ((float)desfoqueInv.at<uchar>(i,j)/255.0));
 		}
	}
}

void getPonderacao() {
  	float x;
  	float conta;
  	float altReg2, posVert2, d2;

  	altReg2 = altReg * img.rows;
  	posVert2 = posVert * img.rows;
  	d2 = d * img.rows;
  	float l1 = img.rows - posVert2 - altReg2/2 ;
  	float l2 = img.rows - posVert2 + altReg2/2 ;

  	for (int i = 0; i < img.rows ; i++) {
      for(int j = 0; j < img.cols; j++) {
			x = i;
			conta = (int)((0.5)*(tanh((x-l1)/d2) - tanh((x-l2)/d2))*255.0);

			desfoque.at<uchar>(i,j)    = conta;
			desfoqueInv.at<uchar>(i,j) = 255 - conta;
		}
	}
}

void changeImg() {
	//Prepara a matriz de ponderacao de acordo com a imagem original:
	desfoque    = img.clone();
	desfoqueInv = img.clone();
	cvtColor(desfoque   , desfoque   , CV_RGB2GRAY);
	cvtColor(desfoqueInv, desfoqueInv, CV_RGB2GRAY);

	//Ramo 01: Gera a matriz saturada:
	increaseSaturation();

	//Ramo 02: Gera a matriz borrada:
	getBlurredImg();

	getPonderacao();
	multiplicaPonderacao();
	addWeighted(saturatedImg, 1, blurredImg, 1, 0.0, result);

	imshow("Tilt Shift", result);
}

void on_trackbar_alpha(int, void*) {
    alpha = (float) alpha_slider/alpha_slider_max;

    altReg = alpha;

    changeImg();
}

void on_trackbar_focus(int, void*) {
    focus = (float) focus_slider/focus_slider_max;
    
    d = focus;

    changeImg();
}

void on_trackbar_position(int, void*) {
    position = (double) position_slider/position_slider_max;
    
    posVert = position;

    changeImg();
}

int main(int argc, char **argv) {
    if(argc < 2) {
        cout << "Argumentos faltando!\nUso: ./tiltshift <caminho_para_imagem>\n";
        return -1;
    }

    float media[] = {
        1, 1, 1,
        1, 1, 1,
        1, 1, 1
    };

    img = imread(argv[1], IMREAD_COLOR);
    
    namedWindow("Tilt Shift", WINDOW_KEEPRATIO);
    resizeWindow("Tilt Shift", 800, 600);

    getBlurredImg();
    increaseSaturation();

    sprintf(TrackbarName, "Alpha: %d", alpha_slider_max);
    createTrackbar(
      TrackbarName,
      "Tilt Shift",
      &alpha_slider,
      alpha_slider_max,
      on_trackbar_alpha  
    );
    
    sprintf(TrackbarName, "Foco: %d", focus_slider_max);
    createTrackbar(
        TrackbarName,
        "Tilt Shift",
        &focus_slider,
        focus_slider_max,
        on_trackbar_focus
    );

    sprintf(TrackbarName, "Centro Focal: %d", position_slider_max);
    createTrackbar(
        TrackbarName,
        "Tilt Shift",
        &position_slider,
        position_slider_max,
        on_trackbar_position
    );

    imshow("Tilt Shift", saturatedImg);

    waitKey(0);
    return 0;
}