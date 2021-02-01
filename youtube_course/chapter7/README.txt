1:
void cv::drawContours(cv::InputOutputArray image, cv::InputArrayOfArrays contours, int contourIdx, const cv::Scalar &color, int thickness = 1, int lineType = 8, cv::InputArray hierarchy = noArray(), int maxLevel = 2147483647, cv::Point offset = cv::Point())
Draws contours outlines or filled contours. The function draws contour outlines in the image if

Parameters:
image – Destination image.
contours – All the input contours. Each contour is stored as a point vector.
contourIdx – Parameter indicating a contour to draw. If it is negative, all the contours are drawn.
color – Color of the contours.
thickness – Thickness of lines the contours are drawn with. If it is negative (for example, thickness=#FILLED ), the contour interiors are drawn.



2:
cv::findContours
findContours() [1/2]
void cv::findContours	(	InputOutputArray 	image,
OutputArrayOfArrays 	contours,
OutputArray 	hierarchy,
int 	mode,
int 	method,
Point 	offset = Point() 
)		

Finds contours in a binary image.

The function retrieves contours from the binary image using the algorithm [193] . The contours are a useful tool for shape analysis and object detection and recognition. See squares.cpp in the OpenCV sample directory.

Note
Since opencv 3.2 source image is not modified by this function.
Parameters
image	Source, an 8-bit single-channel image. Non-zero pixels are treated as 1's. Zero pixels remain 0's, so the image is treated as binary . You can use compare, inRange, threshold , adaptiveThreshold, Canny, and others to create a binary image out of a grayscale or color one. If mode equals to RETR_CCOMP or RETR_FLOODFILL, the input can also be a 32-bit integer image of labels (CV_32SC1).
contours	Detected contours. Each contour is stored as a vector of points (e.g. std::vector<std::vector<cv::Point> >).
hierarchy	Optional output vector (e.g. std::vector<cv::Vec4i>), containing information about the image topology. It has as many elements as the number of contours. For each i-th contour contours[i], the elements hierarchy[i][0] , hierarchy[i][1] , hierarchy[i][2] , and hierarchy[i][3] are set to 0-based indices in contours of the next and previous contours at the same hierarchical level, the first child contour and the parent contour, respectively. If for the contour i there are no next, previous, parent, or nested contours, the corresponding elements of hierarchy[i] will be negative.
mode	Contour retrieval mode, see RetrievalModes
method	Contour approximation method, see ContourApproximationModes
offset	Optional offset by which every contour point is shifted. This is useful if the contours are extracted from the image ROI and then they should be analyzed in the whole image context.




3:
double arcLength(cv::InputArray curve, bool closed)
closed – Flag indicating whether the curve is closed or not.


Calculates a contour perimeter or a curve length. The function computes a curve length or a closed contour perimeter.