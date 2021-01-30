#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

////////////////////////images//////////////////////////
int main() {

string path = "Resources/test.png";
Mat img = imread(path);
Mat imgGray;

cvtColor(img, imgGray, COLOR_BGR2GRAY);//The conversion from a RGB image to gray
//https://docs.opencv.org/3.4/d8/d01/group__imgproc__color__conversions.html#gga4e0972be5de079fed4e3a10e24ef5ef0a353a4b8db9040165db4dacb5bcefb6ea


imshow("Image",img);
imshow("Image Gray",imgGray);
waitKey(0);

}
//export DISPLAY=:0; g++ -o tst1 images_task1.cpp `pkg-config opencv4 --cflags --libs`

/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ export DISPLAY=:0; g++ -o tst1 images.cpp `pkg-config opencv4 --cflags --libs`
g++: error: images.cpp: No such file or directory
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ export DISPLAY=:0; g++ -o tst1 images_task1.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ ./tst1
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ #Ok, we have created a gray image which pops up with the original image.
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ 

*/
