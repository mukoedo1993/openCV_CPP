#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
///////Video////////////////

int main() {

 const string path = "../test_video.mp4";
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