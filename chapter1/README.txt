Three header files.

1:
cv::Mat
Mat is a matrix type introduced by OpenCV to handle images.
Reference: https://docs.opencv.org/master/d3/d63/classcv_1_1Mat.html

2:
cv::imread
The function imread loads an image from the specified file and returns it. 
If the image cannot be read (because of missing file, improper permissions, unsupported or invalid format), 
the function returns an empty matrix
Mat cv::imread	(	const String & 	filename,
int 	flags = IMREAD_COLOR 
)	
Reference: https://docs.opencv.org/3.4/d4/da8/group__imgcodecs.html


3:
cv::imshow
Displays an image in the specified window.
void cv::imshow	(	const String & 	winname,
InputArray 	mat 
)	
Reference: https://docs.opencv.org/master/d7/dfc/group__highgui.html#ga453d42fe4cb60e5723281a89973ee563


cv::waitKey:
waitKey()
int cv::waitKey	(	int 	delay = 0	)	
Waits for a pressed key.
The function waitKey waits for a key event infinitely (when delay≤0 ) 
or for delay milliseconds, when it is positive. 
Reference: https://docs.opencv.org/master/d7/dfc/group__highgui.html#ga5628525ad33f52eab17feebcfba38bd7


cv::VideoCapture::VideoCapture(const String&)
Class for video capturing from video files, image sequences or cameras. 


Glossary:
cv::String
Reference:https://docs.opencv.org/3.4/d1/d8f/classcv_1_1String.html#ad43d5c0176c1c9fce373185909d45a96