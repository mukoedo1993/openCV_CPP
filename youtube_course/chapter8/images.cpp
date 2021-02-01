#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>//new header file
#include <iostream>

using namespace cv;
using namespace std;

////////////////////////images faces detected//////////////////////////
int main() {

string path = "Resources/test.png";
Mat img = imread(path);

CascadeClassifier faceCascade;
faceCascade.load("Resources/haarcascade_frontalface_default.xml");

//To check if it works properly: 
if(faceCascade.empty())
{cout<<"XML file not loaded;\n";}

vector<Rect> faces;
faceCascade.detectMultiScale(img, faces, 1.1, 10);

for(int i = 0; i< faces.size();++i)
{
    rectangle(img,faces[i].tl(),faces[i].br(),Scalar(255, 0 ,255),3);
}

imshow("Img",img);
imwrite("Result/face_detected.jpg",img);
waitKey(0);

}

