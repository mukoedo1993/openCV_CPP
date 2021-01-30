#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////////////////////////////LINE////////////////////////////////////////////////////

int main()
{
    Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
     circle(img, Point(256, 256),155,Scalar(0,69,255));
     rectangle(img, Point(130, 226), Point(382,286), Scalar(0, 69, 255),FILLED);
    line(img, Point(130, 296), Point(382, 296), Scalar(125, 162, 37), 2);

    imshow("Image",img);

    waitKey(0);
}
//export DISPLAY=:0; g++ -o line line.cpp `pkg-config opencv4 --cflags --libs`

/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter4$ export DISPLAY=:0; g++ -o line line.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter4$ ./line
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter4$ 
*/