#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
///////Video////////////////

int main() {

 string path = "test_video.mp4";
 VideoCapture cap(path);
 Mat img;


//Video is a series of images.
//We need to capture them one by one and play them. So, here, we use a while loop.
 while (true) {

 cap.read(img);
 imshow("Image", img);
 waitKey(20);
 }
 //Whenever it finishes, it will produce an error, 
}

/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ g++ -o tst2 Video.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ ./tst2
Unable to init server: Could not connect: Connection refused

(Image:5690): Gtk-WARNING **: 18:05:57.205: cannot open display: 
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ export DISPLAY=:0
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ ./tst2
terminate called after throwing an instance of 'cv::Exception'
  what():  OpenCV(4.2.0) ../modules/highgui/src/window.cpp:376: error: (-215:Assertion failed) size.width>0 && size.height>0 in function 'imshow'

Aborted (core dumped)
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ # A small-size window pops up, and play a video.
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ ./tst2
terminate called after throwing an instance of 'cv::Exception'
  what():  OpenCV(4.2.0) ../modules/highgui/src/window.cpp:376: error: (-215:Assertion failed) size.width>0 && size.height>0 in function 'imshow'

Aborted (core dumped)
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ #The title of the window is Image.
*/