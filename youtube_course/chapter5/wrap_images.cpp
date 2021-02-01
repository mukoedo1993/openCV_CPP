#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


float w=250,h=350;
Mat matrix, matrix1,imgWrap,imgWrap1;
////////////////////////wrap images//////////////////////////
int main() {

string path = "Resources/cards.jpg";
Mat img = imread(path);


Point2f src[4] = {{529,142},{771,190},{405,395},{674,457}};//King Card
Point2f src1[4] = {{64,322},{334,278},{88,626},{400,560}};//Queen Card
Point2f dst[4] = {{0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};
Point2f dst1[4] = {{0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};

matrix = getPerspectiveTransform(src,dst);
matrix1 = getPerspectiveTransform(src1,dst1);
warpPerspective(img, imgWrap, matrix, Point(w,h));
warpPerspective(img, imgWrap1, matrix1, Point(w,h));

for(int i=0;i<4;i++)
{
    circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
}

imshow("Image",img);//The image now is added with circles on four corners of the King Card
imshow("ImageWrap",imgWrap);//We could see that we wrap our target image successfully


imshow("ImageWrap1",imgWrap1);

//output our results:
imwrite("Results/cards.jpg",img);
imwrite("Results/king.jpg",imgWrap);
imwrite("Results/queen.jpg",imgWrap1);
waitKey(0);

}
/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter5$ export DISPLAY=:0; g++ -o tst1 wrap_images.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter5$ ./tst1
^C
*/