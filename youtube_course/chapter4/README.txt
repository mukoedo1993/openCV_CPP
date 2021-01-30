1: 
cv::circle::circle()
void cv::circle	(	InputOutputArray 	img,
Point 	center,
int 	radius,
const Scalar & 	color,
int 	thickness = 1,
int 	lineType = LINE_8,
int 	shift = 0 
)	
Draws a circle.
The function cv::circle draws a simple or filled circle with a given center and radius.


2:cv::rectangle::rectangle()
void cv::rectangle	(	Mat & 	img,
Rect 	rec,
const Scalar & 	color,
int 	thickness = 1,
int 	lineType = LINE_8,
int 	shift = 0 
)	
This is an overloaded member function, provided for convenience. It differs from the above function only in what argument(s) it accepts.
use rec parameter as alternative specification of the drawn rectangle: r.tl() and r.br()-Point(1,1) are opposite corners


3: