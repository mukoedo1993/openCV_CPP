#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

int main()
{
    string path ="Resources/shapes.png";
    Mat img = imread(path);

    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3,3), 3, 0);
    Canny(imgBlur, imgCanny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(imgCanny, imgDil, kernel);


    imshow("Image",img);
     imshow("Image Gray",imgGray);
      imshow("Image blur",imgBlur);
       imshow("Image Canny",imgCanny);
        imshow("Image Dil",imgDil);
         imwrite("Results/Image.png",img);
     imwrite("Results/Image Gray.png",imgGray);
      imwrite("Results/Image blur.png",imgBlur);
       imwrite("Results/Image Canny.png",imgCanny);
        imwrite("Results/Image Dil.png",imgDil);

        waitKey(0);
        // imshow("Image Erode",imgErode);

}
//export DISPLAY=:0; g++ -o tst1 Shapes_Contour_detection.cpp `pkg-config opencv4 --cflags --libs`