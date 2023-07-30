#include "Thumbnail.h"

Thumbnail::Thumbnail(int w, int h)
{
	this->data = cv::Mat(w, h,CV_8UC1);
}

//w : width , h : height , x : position x dans la frame , y : obvi 
Thumbnail::Thumbnail(cv::Mat image, int w, int h, int x, int y)
{
	this->data = cv::Mat(w, h, image.type());
	Fill(image,w,h,x,y);
	Process();
}

void Thumbnail::Process()
{
	graph = new Graph(&data);
}

void Thumbnail::Fill(cv::Mat image, int w, int h, int x, int y)
{
	for (int dx = x; dx < x + w && dx < image.cols; dx++)
	{
		for (int dy = y; dy < y + h && dy < image.rows; dy++)
		{
			data.at<cv::Vec3b>(dy - y, dx - x) = image.at<cv::Vec3b>(dy, dx);
		}
	}
}