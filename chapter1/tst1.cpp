#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////// Images //////////////////////
/*
int main() {

string path = "test.png";
Mat img = imread(path);
imshow("Image",img);
waitKey(0);

}
*/
/*
(base) zcw@mukoedo1993:~/C++_machine_learning_clone/machine_learning_C-/Chapter1/linear_regression/Dlib$ g++ -o tst1 tst1.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/C++_machine_learning_clone/machine_learning_C-/Chapter1/linear_regression/Dlib$ ./tst1
(base) zcw@mukoedo1993:~/C++_machine_learning_clone/machine_learning_C-/Chapter1/linear_regression/Dlib$ #An image pop up,you have to close it, otherwise, the terminal will not end the command above. 
(base) zcw@mukoedo1993:~/C++_machine_learning_clone/machine_learning_C-/Chapter1/linear_regression/Dlib$ 

*/

/////////////// Video //////////////////////
/*
int main() {

 string path = "test_video.mp4";
 VideoCapture cap(path);
 Mat img;

 while (true) {

 cap.read(img);
 imshow("Image", img);
 waitKey(20);
 }
}
*/
/*

(base) zcw@mukoedo1993:~/C++_machine_learning_clone/machine_learning_C-/Chapter1/linear_regression/Dlib$ g++ -o tst1 tst1.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/C++_machine_learning_clone/machine_learning_C-/Chapter1/linear_regression/Dlib$ ./tst1


terminate called after throwing an instance of 'cv::Exception'
  what():  OpenCV(4.2.0) ../modules/highgui/src/window.cpp:376: error: (-215:Assertion failed) size.width>0 && size.height>0 in function 'imshow'

Aborted (core dumped)
(base) zcw@mukoedo1993:~/C++_machine_learning_clone/machine_learning_C-/Chapter1/linear_regression/Dlib$ ./tst1
terminate called after throwing an instance of 'cv::Exception'
  what():  OpenCV(4.2.0) ../modules/highgui/src/window.cpp:376: error: (-215:Assertion failed) size.width>0 && size.height>0 in function 'imshow'

Aborted (core dumped)
*/

///////////////// Webcam //////////////////////

int main() {

 VideoCapture cap(0);
 Mat img;

 while (true) {

 cap.read(img);
 imshow("Image", img);
 waitKey(1);
 }
}
/*
(base) zcw@mukoedo1993:~/C++_machine_learning_clone/machine_learning_C-/Chapter1/linear_regression/Dlib$ g++ -o tst1 tst1.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/C++_machine_learning_clone/machine_learning_C-/Chapter1/linear_regression/Dlib$ ./tst1
[ WARN:0] global ../modules/videoio/src/cap_gstreamer.cpp (935) open OpenCV | GStreamer warning: Cannot query video position: status=0, value=-1, duration=-1
^C 
*/


