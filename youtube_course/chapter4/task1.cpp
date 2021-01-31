#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///draw two circles and show it///////
int main()
{
    Mat img(512, 512, CV_8UC3,/*YOU Have a range of 0-255 or -122 to 121.*/Scalar(255,0,0));
    Mat img1(512, 512, CV_8UC3,/*YOU Have a range of 0-255 or -122 to 121.*/Scalar(255,0,0));

    circle(img, Point(256, 256),155,Scalar(0,69,255));

    circle(img1, Point(256, 256),155,Scalar(0,69,255),FILLED);
    imshow("Image",img);//Image will pop up with a kong1xin1de0 circle.
    imshow("Image1",img1);//Iamge1 will pop up with a filled circle.

    waitKey(0);
}
//export DISPLAY=:0; g++ -o tst1 task1.cpp `pkg-config opencv4 --cflags --libs`
