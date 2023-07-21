#pragma once
#include <opencv2/opencv.hpp>
#include "Frame.h"

using namespace std;

class Video
{
	private:
		cv::VideoCapture* cvVideo;
		int nbFrames;
		string path;
		double fps;

	private:
		void SetupData();

	public:
		Video(string path);
		void Display(string windowName);
		void Open();
		void Close();
		const double getFPS() { return this->fps; };
};

