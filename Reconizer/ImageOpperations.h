#pragma once
#include <opencv2/opencv.hpp>
#include "Frame.h"
#include "Thumbnail.h"

class ImageOpperations
{
	public:
	static cv::Mat UnitedColor(int R, int G, int B, const cv::Mat frameFromVideo);

	static cv::Vec2b ThumbnailFrameTracker(Thumbnail wantedObject, const cv::Mat frameFromVideo);

	static float PSNR(const cv::Mat image1, const cv::Mat image2);
};

