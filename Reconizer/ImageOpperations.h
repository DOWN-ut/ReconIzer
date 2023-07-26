#pragma once
#include <opencv2/opencv.hpp>
#include "Frame.h"

class ImageOpperations
{
	public:
	static cv::Mat UnitedColor(int R, int G, int B, const cv::Mat);
};

