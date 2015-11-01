#include "features.h"


int main( int argc, char** argv )
{ 
	Mat img1 = imread( argv[1], 1 );
	Mat img2;
	 VideoCapture cap(0);
  while(true)
  {
  	
   
    cap >> img2;
  
 
  features_ feature;
  feature.set_detector("ORB");
  feature.set_description("ORB");
  feature.set_matcher("BruteForce-L1");
  feature.set_source_image(img1);
  feature.image_features_(img2);

  if(waitKey(20)==27)
  	{
  		break;
  	}
}
  return(0);
}


