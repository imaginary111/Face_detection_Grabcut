#include "opencv2/opencv.hpp"
#include<iostream>
#include<stdlib.h>
using namespace cv;
using namespace std;


CascadeClassifier face_cascade;
string face_cascade_name = "haarcascade_frontalface_alt.xml";


/*cv::Rect detect(Mat img){
	CascadeClassifier face_cascade;
	return rectangle(0,0,50,50);
}*/



int main(){
	string filename;
	std::vector<Rect> faces;
	face_cascade.load(face_cascade_name);
	cout<< "Enter the name of the image to be processed: " <<endl;
	cin>> filename;
	Mat img = cv::imread(filename);
	//cout<<img<<endl;
	face_cascade.detectMultiScale(img,faces,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(30,30));
	//cout<<faces.size()<<endl;
	for( int i = 0; i < faces.size(); i++ ){
		Mat cropimg = img(Rect(faces[i].x-faces[i].width/4,faces[i].y-faces[i].height/8*3,faces[i].width+faces[i].width/2,faces[i].height+faces[i].height/8*6));
		stringstream a;
		a << i;
		string j=a.str();
		cv::imwrite("crop_detected"+j+".jpg",cropimg);
	}

	for (int i=0;i<faces.size();i++){
		stringstream a;
		a << i;
		string j=a.str();
		filename="crop_detected"+j+".jpg";
		img=cv::imread(filename);
		cv::Rect rectangle(0,0,img.cols-1,img.rows-1);
		cv::Mat result;
		cv::Mat bgModel,fgModel;
		cv::grabCut(img,result,rectangle,bgModel,fgModel,5,cv::GC_INIT_WITH_RECT);
		cv::compare(result,cv::GC_PR_FGD,result,cv::CMP_EQ);
		cv::Mat foreground(img.size(),CV_8UC3,cv::Scalar(255,255,255));
		img.copyTo(foreground,result);
		cv::imwrite("detected"+j+".jpg",foreground);
		//cv::namedWindow("Processed Image");
		//cv::imshow("Processed Image",foreground);
		//cv::waitKey();
	}

	for (int i=0;i<faces.size();i++){
		stringstream a;
		a<<i;
		string j=a.str();
		filename="detected"+j+".jpg";
		img=cv::imread(filename);
		Mat img2 = Mat::zeros( img.size(), img.type() );
		for (int y=0;y<img.rows;y++){
			for (int x=0;x<img.cols;x++){
				if (img.at<Vec3b>(y,x)[0]<60 && img.at<Vec3b>(y,x)[1]<110 && img.at<Vec3b>(y,x)[2]<130){
					img2.at<Vec3b>(y,x)[0]=0;
					img2.at<Vec3b>(y,x)[1]=0;
					img2.at<Vec3b>(y,x)[2]=0;
				}
				else if (img.at<Vec3b>(y,x)[0]==255 && img.at<Vec3b>(y,x)[1]==255 && img.at<Vec3b>(y,x)[2]==255){
					img2.at<Vec3b>(y,x)[0]=img.at<Vec3b>(y,x)[0];
					img2.at<Vec3b>(y,x)[1]=img.at<Vec3b>(y,x)[1];
					img2.at<Vec3b>(y,x)[2]=img.at<Vec3b>(y,x)[2];
				}
				else{
					img2.at<Vec3b>(y,x)[0]=79;
					img2.at<Vec3b>(y,x)[1]=142;
					img2.at<Vec3b>(y,x)[2]=211;
				}

			}
		}
		cv::imwrite("result"+j+".jpg",img2);
		
	}
	cout<<"\n\n\n******IMAGES SAVED IN SAME DIRECTORY******\n\n\n";
	return 0;
}


