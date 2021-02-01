1:
namedWindow:
Creates a window.
The function namedWindow creates a window that can be used as a 
placeholder for images and trackbars. Created windows are referred to by their names.
void cv::namedWindow	(	const String & 	winname,
int 	flags = WINDOW_AUTOSIZE 
)	


2:
◆ createTrackbar()
int cv::createTrackbar	(	const String & 	trackbarname,
const String & 	winname,
int * 	value,
int 	count,
TrackbarCallback 	onChange = 0,
void * 	userdata = 0 
)		
#include <opencv2/highgui.hpp>
Creates a trackbar and attaches it to the specified window.
The function createTrackbar creates a trackbar (a slider or range control) with the 
specified name and range, assigns a variable value to be a position synchronized with 
the trackbar and specifies the callback function onChange to be called on the trackbar position change. 
The created trackbar is displayed in the specified window winname.


3:
inRange
inRange()
void cv::inRange	(	InputArray 	src,
InputArray 	lowerb,
InputArray 	upperb,
OutputArray 	dst 
)		
#include <opencv2/core.hpp>
Checks if array elements lie between the elements of two other arrays.
The function checks the range as follows:
https://docs.opencv.org/3.4/d2/de8/group__core__array.html#ga48af0ab51e36436c5d04340e036ce981
Parameters
src	first input array.
lowerb	inclusive lower boundary array or a scalar.
upperb	inclusive upper boundary array or a scalar.
dst	output array of the same size as src and CV_8U type.


4:
HSL (hue, saturation, lightness) and HSV (hue, saturation, value, also known as HSB or hue,
 saturation, brightness) are alternative representations of the RGB color model, designed in the 1970s 
 by computer graphics researchers to more closely align with the way human vision perceives 
 color-making attributes. In these models, colors of each hue are arranged in a radial slice,
 around a central axis of neutral colors which ranges from black at the bottom to white at the top. 