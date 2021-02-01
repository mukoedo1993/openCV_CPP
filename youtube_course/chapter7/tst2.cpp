#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

//Mat::Mat(const Mat&)
/*
Array that (as a whole or partly) is assigned to the constructed matrix. 
No data is copied by these constructors. 
Instead, the header pointing to m data or its sub-array is constructed and associated with it. 
*/

void GetContours(Mat imgDil, Mat img)//copy constructor here:
{
    vector<vector<Point>> contours ;
    vector<Vec4i>hierarchy;//Vec4i: a vector of four integers
    
    findContours(imgDil,contours,hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
   
//  drawContours(img,contours,-1,Scalar(255,0,255),2);//Here, -1 means draw all contours.

    for(int i=0;i<contours.size();++i)
    {
        int area = contourArea(contours[i]);//area

        cout <<"The area is: "<<area<<'\n';

        vector<vector<Point>>conPoly(contours.size()); 
        vector<Rect> boundRect(contours.size());
        string objectType;

        if(area>1000)
        {
          float peri = arcLength(contours[i],true);
          approxPolyDP(contours[i],conPoly[i],0.02*peri,true);//Give us an approximation.. Whether its
          //rectangle, triangle, or anything else...
          drawContours(img,conPoly,i,Scalar(255,0,255),2);
          cout<<" conPoly[i]'s size is:"<<conPoly[i].size()<<'\n';

          boundRect [i] = boundingRect(conPoly[i]);
          rectangle(img, boundRect[i].tl()/*The top-left corner*/, 
          boundRect[i].br()/*The bottom-right corner*/, Scalar(0,255,0),5);

          int objCor = static_cast<int>(conPoly[i].size()); 
          float aspRatio = static_cast<float>(boundRect[i].width) / static_cast<float>(boundRect[i].height);
           switch(objCor)
           {
               case 3:objectType="Triangle";break;
               case 4:
              
              if (aspRatio> 0.95 && aspRatio< 1.05){ objectType = "Square"; }
              else { objectType = "Rect";}
              
               break;
               default: if(objCor>4)objectType="Circle";
               else throw std::exception();break;
           }
 putText(img,objectType,{boundRect[i].x,boundRect[i].y-5},FONT_HERSHEY_PLAIN,1,Scalar(0,69,255),1);
        }
    }
}

int main()
{
    string path ="Resources/shapes.png";
    Mat img = imread(path);

    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3,3), 3, 0);
    Canny(imgBlur, imgCanny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(imgCanny, imgDil, kernel);

    GetContours(imgDil,img);

    imshow("Image_contour",img);
  
         imwrite("Results/Image_contour.png",img);
   

        waitKey(0);
        // imshow("Image Erode",imgErode);

}
//export DISPLAY=:0; g++ -o tst2 tst2.cpp `pkg-config opencv4 --cflags --libs`
/*
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter7$ export DISPLAY=:0; g++ -o tst2 tst2.cpp `pkg-config opencv4 --cflags --libs`
(base) zcw@mukoedo1993:~/openCV_clone/openCV_CPP/youtube_course/chapter7$ ./tst2
The area is: 35947
 conPoly[i]'s size is:4
The area is: 37952
 conPoly[i]'s size is:8
The area is: 5084
 conPoly[i]'s size is:3
The area is: 11334
 conPoly[i]'s size is:4
The area is: 33486
 conPoly[i]'s size is:4
The area is: 185
The area is: 21325
 conPoly[i]'s size is:3
The area is: 11437
 conPoly[i]'s size is:4
The area is: 8213
 conPoly[i]'s size is:3
The area is: 7541
 conPoly[i]'s size is:8
^C
*/
