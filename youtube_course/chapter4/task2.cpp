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

    circle(img, Point(256, 256), 155, Scalar(0, 69, 255));//
     circle(img1, Point(256, 256), 155, Scalar(0, 69, 255),FILLED);//The circle is filled here.

    imshow("Image",img);
    imshow("Image1",img1);

    waitKey(0);
}

//export DISPLAY=:0; g++ -o tst2 task2.cpp `pkg-config opencv4 --cflags --libs`
/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter4$ export DISPLAY=:0; g++ -o tst2 task2.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter4$ ./tst2
^C
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter4$ 
*/
//Image and Image1
