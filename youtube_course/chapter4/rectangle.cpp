#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////////////////////////////CIRCLE////////////////////////////////////////////////////


//draw a background
int main()
{
    Mat img(512, 512, CV_8UC3,/*YOU Have a range of 0-255 or -122 to 121.*/Scalar(255,0,0));
     Mat img1(512, 512, CV_8UC3,/*YOU Have a range of 0-255 or -122 to 121.*/Scalar(255,0,0));

    rectangle(img1, Point(130, 226), Point(382,286), Scalar(0, 69, 255),FILLED);//Scalar is the color BGR value...
     rectangle(img, Point(130, 226), Point(382,286), Scalar(255, 255, 255),3);

    imshow("Image",img);
    imshow("Image1",img1);

    waitKey(0);
}

//export DISPLAY=:0; g++ -o rectangle rectangle.cpp `pkg-config opencv4 --cflags --libs`
//(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter4$ ./rectangle