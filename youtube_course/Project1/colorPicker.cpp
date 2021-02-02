#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;



////////////////////////Color Detection of shapes.png//////////////////////////
int main() {


int hmin = 0, smin = 0, vmin = 0;
int hmax = 179,  smax= 255, vmax= 255;



VideoCapture cap(0);
Mat img,img1,mask;


namedWindow("Trackbars",(640,200));
createTrackbar("Hue Min","Trackbars",&hmin, 179);
createTrackbar("Hue Max","Trackbars",&hmax, 179);
createTrackbar("Saturation Min","Trackbars",&smin, 255);
createTrackbar("Saturation Max","Trackbars",&smax, 255);
createTrackbar("Val Min","Trackbars",&vmin, 255);
createTrackbar("Val Max","Trackbars",&vmax, 255);


//output our results:
while(true){
    cap.read(img);
cvtColor(img,img1,COLOR_BGR2HSV);//HSV: hue saturation value

Scalar lower(hmin, smin, vmin);
Scalar upper(hmax, smax, vmax);

inRange(img1,lower, upper,mask);
imshow("image", img);
cout<<hmin<<", "<<smin<<", "<<vmin<<", "<<hmax<<", "<<smax<<", "<<vmax<<"\n";
imshow("imageMASK", mask);
waitKey(1);

   }
}

//export DISPLAY=:0; g++ -o tst1 colorPicker.cpp `pkg-config opencv4 --cflags --libs`