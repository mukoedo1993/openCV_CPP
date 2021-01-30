#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

////////////////////////Image dilation and Erosion//////////////////////////
//https://docs.opencv.org/3.4/db/df6/tutorial_erosion_dilatation.html

/*
The Canny edge detector is an edge detection operator that uses a 
multi-stage algorithm to detect a wide range of edges in images. 
It was developed by John F. Canny in 1986. 
Canny also produced a computational theory of edge detection explaining why the technique works.
*/

int main() {

string path = "Resources/test.png";
Mat img = imread(path);
Mat imgBlur,imgCanny, imgDil, imgErode;

GaussianBlur(img,imgBlur,Size(3,3),3,0);
Canny(imgBlur, imgCanny, 25, 75);

Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3) );//Size should BOTH BE ODD!!
/*
enum  	cv::MorphShapes {
  cv::MORPH_RECT = 0,
  cv::MORPH_CROSS = 1,
  cv::MORPH_ELLIPSE = 2
}
*/
dilate(imgCanny, imgDil, kernel);
erode(imgDil, imgErode, kernel);

imshow("Image",img);
imshow("Image Canny",imgCanny);
imshow("Image Dilation",imgDil);
imshow("Image Erosion",imgErode);
//cv::Size:  Template class for specifying the size of an image

waitKey(0);

}

//export DISPLAY=:0; g++ -o tst4 images_task4.cpp `pkg-config opencv4 --cflags --libs`

/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ export DISPLAY=:0; g++ -o tst4 images_task4.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter2$ ./tst4
*/

//Conclusion: We get the img. Then, we add GaussianNoise. Then, we use Canny to process it.
//We then add dilation. Then, erode the dilated image.
