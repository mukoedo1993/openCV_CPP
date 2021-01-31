#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////////////////////////////FORBIDDEN SIGN////////////////////////////////////////////////////


//draw a background
int main()
{
    Mat img(512, 512, CV_8UC3,/*YOU Have a range of 0-255 or -122 to 121.*/Scalar(255,0,0));
    

     circle(img, Point(256, 256),155, Scalar(0, 69, 255),FILLED);//The circle is filled here.
      rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255),FILLED);//
      line(img,Point(130,296),Point(382,296),Scalar(255,255,255));//add a dash below the sign

      putText(img,"mukoedo1993",Point(137,262),FONT_HERSHEY_COMPLEX,0.75,Scalar(0,69,255),2);

    imshow("Image",img);// pop up an image with unfilled rectangle
    imwrite("Resources/forbidden_sign_chap4.png",img);//Please check the file.

    waitKey(0);
}

//export DISPLAY=:0; g++ -o forbidden_sign forbidden_sign.cpp `pkg-config opencv4 --cflags --libs`
/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter4$ export DISPLAY=:0; g++ -o forbidden_sign forbidden_sign.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter4$ ./forbidden_sign
^C
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter4$ 
*/