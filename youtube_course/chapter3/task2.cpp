#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///Resize///
int main() {

string path = "Resources/test.png";
Mat img = imread(path);
Mat imgResize,imgResize2;

cout << img.size()<<endl;
resize(img,imgResize,Size(640,480));
resize(img,imgResize2,Size(),0.5,0.5);//scale rather than exact size
cout << imgResize.size()<<endl;
cout << imgResize2.size()<<endl;
imshow("Image",img);
imshow("Image Resize",imgResize);
waitKey(0);

}
//export DISPLAY=:0; g++ -o tst2 task2.cpp `pkg-config opencv4 --cflags --libs`
/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter3$ export DISPLAY=:0; g++ -o tst2 task2.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter3$ ./tst2
[768 x 559]
[640 x 480]
[384 x 280]
^C
*/