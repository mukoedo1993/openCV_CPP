#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;


vector<vector<int>>myColors {{110,36,45,128,126,181},//a dark blue pencil
                             {0,169,139,10,255,255,255},//a pink pencil
                             //{139,55,135,179,123,188}  //a purple pencil(DOEN'T WORK WELL)
                            };

vector<Scalar>myColorValues{
                            {0, 0, 139},//dark blue
                            {255, 192, 203},//pink 
                            //

};
Mat img;
vector<vector<int>> newPoints;




Point GetContours( Mat image)//copy constructor here:
{
    vector<vector<Point>> contours ;
    vector<Vec4i>hierarchy;//Vec4i: a vector of four integers
    
    findContours(image,contours,hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
   
//  drawContours(img,contours,-1,Scalar(255,0,255),2);//Here, -1 means draw all contours.
        vector<vector<Point>>conPoly(contours.size()); 
        vector<Rect> boundRect(contours.size());

        Point myPoint(0,0);

    for(int i=0;i<contours.size();++i)
    {
        int area = contourArea(contours[i]);//area

        cout <<"The area is: "<<area<<'\n';


        string objectType="";

        if(area>100)
        {
          float peri = arcLength(contours[i],true);
          approxPolyDP(contours[i],conPoly[i],0.02*peri,true);//Give us an approximation.. Whether its
          //rectangle, triangle, or anything else...
          
          cout<<" conPoly[i]'s size is:"<<conPoly[i].size()<<'\n';

          boundRect [i] = boundingRect(conPoly[i]);
          myPoint.x = boundRect[i].x + boundRect[i].width/2;
          myPoint.y = boundRect[i].y;

          drawContours(img,conPoly,i,Scalar(255,0,255),20);


          rectangle(img, boundRect[i].tl()/*The top-left corner*/, 
          boundRect[i].br()/*The bottom-right corner*/, Scalar(0,255,0),5);

        }
    }
    return myPoint;
}


vector<vector<int>> findColor(Mat img)
{
    Mat imgHSV;
  cvtColor(img, imgHSV, COLOR_BGR2HSV);

 for(int i = 0;i<myColors.size();++i)
 {
  Scalar lower(myColors[i][0],myColors[i][1],myColors[i][2]);
  Scalar upper(myColors[i][3],myColors[i][4],myColors[i][5]);
  Mat mask;
  inRange(imgHSV, lower, upper, mask);
  Point myPoint = GetContours(mask);

  if(myPoint.x!=0&&myPoint.y!=0)
  newPoints.push_back({myPoint.x,myPoint.y,i});
  
  
  imshow(to_string(i),mask);
 }
 return newPoints;
}


void drawOnCanvas(const vector<vector<int>>&newPoints,const vector<Scalar>&myColorValues)
{
    for(int i=0;i<newPoints.size();++i)
    {
        circle(img, Point(newPoints[i][0],newPoints[i][1]),10,myColorValues[newPoints[i][2]],FILLED);
    }
}




int main() {

 VideoCapture cap(0);//0 is our webcam id.

   std::string time="Results/"+ static_cast<string>(__TIME__)+".png";
 while (true) {

 cap.read(img);
 newPoints = findColor(img);
 drawOnCanvas(newPoints, myColorValues);

 imshow("Image", img);
 imwrite(time,img);
 waitKey(1);
 }
}
//export DISPLAY=:0; g++ -o tst1 Project1.cpp `pkg-config opencv4 --cflags --libs`