#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Project 3 – License Plate Detector //////////////////////

int main() {

Mat img;
VideoCapture cap(0);

CascadeClassifier plateCascade;
plateCascade.load("Resources/haarcascade_russian_plate_number.xml");

if (plateCascade.empty()) { cout << "XML file not loaded" << endl; }

vector<Rect> plates;

while (true) {

cap.read(img);
plateCascade.detectMultiScale(img, plates, 1.1, 10);

for (int i = 0; i < plates.size(); i++)
{
Mat imgCrop = img(plates[i]);
imshow(to_string(i), imgCrop);
imwrite("Resources/Plates/" + to_string(i) + ".png", imgCrop);
rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);
}

imshow("Image", img);
waitKey(1);
}
}

//Record: 
//export DISPLAY=:0; g++ -o Project3 Project3.cpp `pkg-config opencv4 --cflags --libs`
/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ export DISPLAY=:0; g++ -o tst2 WebCam.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ ./tst2
[ WARN:0] global ../modules/videoio/src/cap_gstreamer.cpp (935) open OpenCV | GStreamer warning: Cannot query video position: status=0, value=-1, duration=-1
^C
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/chapter1$ #The WebCam is called by our code here. 

*/