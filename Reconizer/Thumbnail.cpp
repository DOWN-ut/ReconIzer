#include "Thumbnail.h"

Thumbnail::Thumbnail(int w, int h)
{
	this->data = cv::Mat(w, h,CV_8UC1);
}

//w : width , h : height , x : position x dans la frame , y : obvi 
Thumbnail::Thumbnail(Frame* f, int w, int h, int x, int y)
{
	this->data = cv::Mat(w, h, f->Image().type());
	for (int dx = x; dx < x+w && dx < f->Image().cols; dx++)
	{
		for (int dy = y; dy < y+h && dy < f->Image().rows; dy++)
		{
			data.at<cv::Vec3b>(dy-y, dx-x) = f->Image().at<cv::Vec3b>(dy, dx);
		}
	}
}