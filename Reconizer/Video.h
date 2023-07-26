#pragma once
#include <opencv2/opencv.hpp>
#include "Frame.h"

using namespace std;

class Video
{
	private:
		cv::VideoCapture* cvVideo;

		int nbFrames;
		Frame** frames;

		string path;
		double fps;

	private:
		void SetupData();
		void SetupFrames();

	public:
		Video(string path);
		void Display(string windowName);
		void Open();
		void Close();
		const double FPS() { return this->fps; };
};

