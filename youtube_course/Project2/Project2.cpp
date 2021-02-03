#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<functional>
using namespace cv;
using namespace std;

////////////////////////images//////////////////////////
Mat imgOriginal, imgBlur,imgGray, imgCanny, imgPre ,imgDil, imgErode, imgThre, imgWarp, imgCrop;

vector<Point>initialPoints, docPoints;

float w = 420, h =596;

vector<Point> GetContours( Mat image)
{
    vector<vector<Point>> contours ;
    vector<Vec4i>hierarchy;//Vec4i: a vector of four integers
    
    findContours(image,contours,hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
   
//  drawContours(img,contours,-1,Scalar(255,0,255),2);//Here, -1 means draw all contours.
        vector<vector<Point>>conPoly(contours.size()); 
        vector<Rect> boundRect(contours.size());

      vector<Point>biggest;
      int maxArea(0);

    for(int i=0;i<contours.size();++i)
    {
        int area = contourArea(contours[i]);//area

        cout <<"The area is: "<<area<<'\n';


      
        //Do filtration with area:
        if(area>1000)
        {
          float peri = arcLength(contours[i],true);
          approxPolyDP(contours[i],conPoly[i],0.02*peri,true);//Give us an approximation.. Whether its
          //rectangle, triangle, or anything else...

            //Compared to chap. 2, in this project, we don't need bounding rectangle.
          if(area > maxArea&& conPoly[i].size()==4){

              biggest = {conPoly[i][0], conPoly[i][1], conPoly[i][2], conPoly[i][3]};
              maxArea = area;
               //drawContours(imgOriginal,conPoly,i,Scalar(255,0,255),10);

          }
         

          //rectangle(imgOriginal, boundRect[i].tl()/*The top-left corner*/, 
          //boundRect[i].br()/*The bottom-right corner*/, Scalar(0,255,0),5);

        }
    }
    return biggest;
}



Mat Preprocessing(Mat img)
{
    cvtColor(img, imgGray,COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur,Size(3,3),3,0);
    Canny(imgBlur, imgCanny, 25, 75);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(imgCanny, imgDil, kernel);
    erode(imgDil, imgErode, kernel);

    return imgDil;

}




void drawPoints(vector<Point>points, Scalar color)
{
    for(int i = 0; i < points.size(); ++i)
    {
        circle(imgOriginal, points[i], 10, color, FILLED);
        putText(imgOriginal, to_string(i),points[i],FONT_HERSHEY_PLAIN,5, color, 2);
    }
}

vector<Point> reorder(const vector<Point>& initialPoints)
{
    vector<Point> newPoints;
    vector<int> sumPoints, subPoints;
    for(int i=0;i<4;++i){
        sumPoints.push_back(initialPoints[i].x+initialPoints[i].y);
        subPoints.push_back(initialPoints[i].x-initialPoints[i].y);
    }

    newPoints.push_back(initialPoints[min_element(sumPoints.cbegin(),sumPoints.cend())-sumPoints.cbegin()]); // 0
    newPoints.push_back(initialPoints[max_element(subPoints.cbegin(),subPoints.cend())-subPoints.cbegin()]); //1
    newPoints.push_back(initialPoints[min_element(subPoints.cbegin(),subPoints.cend())-subPoints.cbegin()]); //2

    newPoints.push_back(initialPoints[max_element(sumPoints.cbegin(),sumPoints.cend())-sumPoints.cbegin()]); // 3

    return newPoints;
}


Mat getWarp(Mat img, vector<Point> points, float w ,float h)
{
   Point2f src[4] = {points[0], points[1], points[2], points[3]};
   Point2f dst[4] = {{0.0f, 0.0f},{w , 0.0f},{0.0f, h},{w,h}};


   Mat Matrix = getPerspectiveTransform(src, dst);
   warpPerspective(img, imgWarp, Matrix, Point(w,h));


   return imgWarp;
}

int main() {

string path = "Resources/paper.jpg";
imgOriginal = imread(path);
resize(imgOriginal, imgOriginal, Size(), 0.5, 0.5);


//Preprocessing: 
imgThre = Preprocessing(imgOriginal);

//Get the biggest contour:
initialPoints = GetContours(imgThre);
//drawPoints(initialPoints, Scalar(0,0,255));
docPoints = reorder(initialPoints);
drawPoints(docPoints, Scalar(0,255,0));

//Wrap:
imgWarp = getWarp(imgOriginal, docPoints, w, h);

//Crap: 
int cropVal= 5;
Rect roi(cropVal, cropVal, w - (2 * cropVal), h - (2 * cropVal));
imgCrop = imgWarp(roi);



imshow("Results/Image",imgOriginal);
imshow("/ResultsImage Dilation",imgThre);
imshow("ImgWarp",imgWarp);
imshow("ImgCrop",imgCrop);
imwrite("Results/ImgWarp.jpg",imgWarp);
imwrite("Results/ImgCrop.jpg",imgCrop);
waitKey(0);

}

//#ON TERMINAL: 
//export DISPLAY=:0;g++ -o tst1 Project2.cpp `pkg-config opencv4 --cflags --libs`
