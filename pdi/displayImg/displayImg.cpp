#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv) {
	Mat inputImage = imread(argv[1], CV_LOAD_IMAGE_COLOR); 

	namedWindow("Input Image", WINDOW_AUTOSIZE);
	imshow("Input Image", inputImage);

	waitKey(0);
	return 0;
}