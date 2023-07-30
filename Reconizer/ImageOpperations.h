#pragma once
#include <opencv2/opencv.hpp>
#include "Frame.h"
#include "Thumbnail.h"

class ImageOpperations
{
	public:
	static cv::Mat UnitedColor(int R, int G, int B, const cv::Mat frameFromVideo);

	static vector<int> ProcessWidnows(Frame* frame, Thumbnail* thumbnail);
	static cv::Vec3f ThumbnailFrameTrackerWholeFrame(Thumbnail* wantedObject, const cv::Mat frameFromVideo, float precision);
	static cv::Vec3f ThumbnailFrameTrackerWindows(Thumbnail* wantedObject, const cv::Mat frameFromVideo, float precision);

	static float PSNR(const cv::Mat image1, const cv::Mat image2, int x, int y);
};

