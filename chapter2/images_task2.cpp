#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

////////////////////////images with Gaussian Blur//////////////////////////
int main() {

string path = "Resources/test.png";
Mat img = imread(path);
Mat imgBlur;

GaussianBlur(img,imgBlur,Size(7,7),5,0);

imshow("Image",img);
imshow("Image Blur",imgBlur);
//cv::Size:  Template class for specifying the size of an image or rectangle
waitKey(0);

}
//export DISPLAY=:0; g++ -o tst1 images_task2.cpp `pkg-config opencv4 --cflags --libs`
/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ export DISPLAY=:0; g++ -o tst1 images_task2.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ ./tst1
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ #OK, we get what we need pop up.
*/