 #include "features.h"

using namespace cv;
using namespace std;


//constructors
  features_::features_(cv::Mat inimg1, cv :: Mat inimg2)
  {
    img1 = inimg1;
    img2 = inimg2;
  }
  features_::features_()
  {

  }

  void features_::set_detector(string a)
  {
    if(a.empty())
    {
      cout<"no detector is been set";
      return;
    }
    option.detectorType = a;
    return ;
    }
      
void features_::set_description(string a)
{
  if(a.empty())
    {
      cout<"no detector is been set";
      return;
    }
  option.descriptorType = a;
return;
}

void features_::set_matcher(string a)
{
  if(a.empty())
    {
      cout<"no detector is been set";
      return;
    }
  option.matcherType = a;
  }

int features_::findKeypoints() {
cv::Ptr<FeatureDetector> detector = FeatureDetector::create(option.detectorType);
cout<<"deetcted\n";
if ( detector.empty() )
{
cout << "Can not create detector or descriptor extractor or descriptor matcher of given types 4s" << endl;
return -1;
}
detector->detect(img1, keypoints1);
cout<<"deetcted\n";
//detector->detect(img2, keypoints2);
return 0;
}

int features_::findDescriptor() {
//Ptr<DescriptorExtractor> descri
cv::Ptr<DescriptorExtractor> descriptor = DescriptorExtractor::create(option.descriptorType);
if ( descriptor.empty() ) {
cout << "Can not create detector or descriptor extractor or descriptor matcher of given types" << endl;
return -1;
}
descriptor->compute(img1, keypoints1, descriptors1);
//descriptorExtractor->compute(img2, keypoints2, descriptors2);
return 0;
}

int features_::set_source_image(cv::Mat inimg)
{
  if( inimg.empty())
  {
    cout<<"no input image";
    return -1;
  }
  cout<<"setting";
img1 = inimg.clone(); 
findKeypoints();
findDescriptor();
return 0;
}

int features_::image_features_(Mat img)
{ 


 if(img.empty())
 {
  cout<<"error";
  return -1;
 }
  
  Mat img2(img);
  
  cv::Ptr<FeatureDetector> detector1 = FeatureDetector::create(option.detectorType);

  //imshow("image",img2);
  if ( detector1.empty() )
  {
  cout << "Can not create detector or descriptor extractor or descriptor matcher of given types" << endl;
  return -1;
  }
  detector1->detect(img2, keypoints2);
  cv::Ptr<DescriptorExtractor> descriptor = DescriptorExtractor::create(option.descriptorType);
  descriptor->compute(img2, keypoints2, descriptors2);
  cout<<"keypoints 2"<<keypoints2.size()<<endl;
  Ptr<DescriptorMatcher> descriptorMatcher = DescriptorMatcher::create(option.matcherType);
  vector<DMatch>  matches;
  descriptorMatcher->match( descriptors1, descriptors2, matches);
  cout<<"matches"<<matches.size()<<endl;
  Mat imgMatches; // image for storing matches
  drawMatches( img1, keypoints1, img2, keypoints2, matches, imgMatches, Scalar::all(-1), Scalar::all(-1),
vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
// Show detected matches
imshow( "Matches", imgMatches );

   return 0;


}
