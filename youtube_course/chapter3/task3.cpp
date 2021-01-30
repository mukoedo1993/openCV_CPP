#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///Crop the image///
int main() {

string path = "Resources/test.png";
Mat img = imread(path);
Mat imgResize, imgCrop;

resize(img, imgResize, Size(),0.5,0.5);


Rect roi(200, 100, 300, 300);
//Rect_: Template class for 2D rectangles.
//Rect2i = typedef Rect_<int>
//Rect = typedef Rect2i

imgCrop = img(roi);

imshow("image", img);
imshow("image Resize", imgResize);
imshow("image Crop", imgCrop);
waitKey(0);

}
////export DISPLAY=:0; g++ -o tst3 task3.cpp `pkg-config opencv4 --cflags --libs`
/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter3$ export DISPLAY=:0; g++ -o tst3 task3.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter3$ ./tst3
*/