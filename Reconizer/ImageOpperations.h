#pragma once
#include <opencv2/opencv.hpp>
#include "Frame.h"
#include "Thumbnail.h"

class ImageOpperations
{
	public:
	static cv::Mat UnitedColor(int R, int G, int B, const cv::Mat frameFromVideo);

	static vector<int> ProcessWindows(Frame* frame, Thumbnail* thumbnail);
	static cv::Vec3f ThumbnailFrameTrackerWholeFrame(Thumbnail* wantedObject, const cv::Mat frameFromVideo, float precision);
	static cv::Vec3f ThumbnailFrameTrackerWindows(Thumbnail* wantedObject, Frame* frame, float precision);

	static cv::Vec3f ToHSL(cv::Vec3b rgb);

	static float PSNR(const cv::Mat image1, const cv::Mat image2, int x, int y);
};

