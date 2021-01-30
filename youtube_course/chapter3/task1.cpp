#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///Show the size and print ///
int main() {

string path = "Resources/test.png";
Mat img = imread(path);
Mat imgResize;

cout << img.size()<<endl;
//resize(img,imgResize,Size(3,3));

imshow("Image",img);
waitKey(0);

}

//export DISPLAY=:0; g++ -o tst1 task1.cpp `pkg-config opencv4 --cflags --libs`
/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter3$ export DISPLAY=:0; g++ -o tst1 task1.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter3$ ./tst1
[768 x 559]
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter3$ 
*/