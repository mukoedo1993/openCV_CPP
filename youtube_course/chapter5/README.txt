1:Wrap perspective:
 warpPerspective()
void cv::warpPerspective	(	InputArray 	src,
OutputArray 	dst,
InputArray 	M,
Size 	dsize,
int 	flags = INTER_LINEAR,
int 	borderMode = BORDER_CONSTANT,
const Scalar & 	borderValue = Scalar() 
)		
Applies a perspective transformation to an image.

The function warpPerspective transforms the source image using the specified matrix:



2:getPerspectiveTransform()

Mat cv::getPerspectiveTransform	(	InputArray 	src,
InputArray 	dst,
int 	solveMethod = DECOMP_LU 
)	
Calculates a perspective transform from four pairs of the corresponding points.

An alternative constructor: 
Mat cv::getPerspectiveTransform	(	const Point2f 	src[],
const Point2f 	dst[],
int 	solveMethod = DECOMP_LU 
)	