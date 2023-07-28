#include "Thumbnail.h"

Thumbnail::Thumbnail(int w, int h)
{
	this->data = cv::Mat(w, h,CV_8UC1);
}

Thumbnail::Thumbnail(Frame* f, int w, int h, int x, int y)
{
	this->data = cv::Mat(w, h, CV_8UC1);
	for (int dx = x; dx < w && dx < f->Image().cols; dx++)
	{
		for (int dy = y; dy < h && dy < f->Image().rows; dy++)
		{
			data.at<cv::Vec3b>(y-h, x-w) = f->Image().at<cv::Vec3b>(y, x);
		}
	}
}