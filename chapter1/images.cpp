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
imshow("Image",img);
waitKey(0);

}

//ON TERMINAL: 
/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ g++ -o tst1 images.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ ./tst1
Unable to init server: Could not connect: Connection refused

(Image:5145): Gtk-WARNING **: 17:56:26.898: cannot open display: 
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ export DISPLAY=:0
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ g++ -o tst1 images.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ ./tst1
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ #The Resources/test.png is opened successfully by our CPP file.

*/