#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

////////////////////////Canny Algorithm//////////////////////////
/*
The Canny edge detector is an edge detection operator that uses a 
multi-stage algorithm to detect a wide range of edges in images. 
It was developed by John F. Canny in 1986. 
Canny also produced a computational theory of edge detection explaining why the technique works.
*/

int main() {

string path = "Resources/test.png";
Mat img = imread(path);
Mat imgBlur,imgCanny;

GaussianBlur(img,imgBlur,Size(3,3),3,0);
Canny(imgBlur, imgCanny, 50, 150);

imshow("Image",img);
imshow("Image Canny",imgCanny);
//cv::Size:  Template class for specifying the size of an image

waitKey(0);

}

//export DISPLAY=:0; g++ -o tst1 images_task3.cpp `pkg-config opencv4 --cflags --libs`
/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ export DISPLAY=:0; g++ -o tst1 images_task3.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ ./tst1
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ #Ok, we get the product of Canny Algorithm.
*/