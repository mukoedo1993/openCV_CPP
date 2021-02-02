#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

 VideoCapture cap(0);//0 is our webcam id.
 Mat img;

 while (true) {

 cap.read(img);
 imshow("Image", img);
 waitKey(1);
 }
}


//Record: 
//export DISPLAY=:0; g++ -o tst2 WebCam.cpp `pkg-config opencv4 --cflags --libs`
/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ export DISPLAY=:0; g++ -o tst2 WebCam.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ ./tst2
[ WARN:0] global ../modules/videoio/src/cap_gstreamer.cpp (935) open OpenCV | GStreamer warning: Cannot query video position: status=0, value=-1, duration=-1
^C
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ #The WebCam is called by our code here. 

*/