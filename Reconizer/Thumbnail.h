#pragma once
#include <opencv2/opencv.hpp>
#include "Frame.h"

class Thumbnail
{
protected:
	cv::Mat data;

public:
	cv::Mat Image() { return data; }

	void Show() { cv::imshow("Current Thumbnail", Image()); }

	Thumbnail(){}
	Thumbnail(int w, int h);
	Thumbnail(Frame* f, int w, int h, int x, int y);
};
