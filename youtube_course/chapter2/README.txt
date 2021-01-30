1:
cv::cvtColor(img, imgGray, COLOR_BGR2GRAY);//The conversion from a RGB image to gray
//https://docs.opencv.org/3.4/d8/d01/group__imgproc__color__conversions.html#gga4e0972be5de079fed4e3a10e24ef5ef0a353a4b8db9040165db4dacb5bcefb6ea


2:
cv::Size()
Template class for specifying the size of an image or rectangle
Reference: https://docs.opencv.org/3.4/d6/d50/classcv_1_1Size__.html


3:
cv::Canny()
void cv::Canny(cv::InputArray image, cv::OutputArray edges, 
double threshold1, double threshold2, int apertureSize = 3, 
bool L2gradient = false)
+1 overload
Finds edges in an image using the Canny algorithm
Reference: https://docs.opencv.org/3.4/dd/d1a/group__imgproc__feature.html#ga04723e007ed888ddf11d9ba04e2232de


4:
cv::GetStructureElement()
cv::Mat cv::getStructuringElement(int shape, cv::Size ksize, cv::Point anchor = cv::Point(-1, -1))
Returns a structuring element of the specified size and shape for morphological operations. 
The function constructs and returns the structuring element that can be further passed to #erode, 
#dilate or #morphologyEx. But you can also construct an arbitrary 
binary mask yourself and use it as the structuring element.

Parameters:
shape – Element shape that could be one of #MorphShapes
ksize – Size of the structuring element.
anchor – Anchor position within the element. The default value


5: