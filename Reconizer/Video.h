#pragma once
#include <opencv2/opencv.hpp>
#include "Frame.h"

using namespace std;

#ifndef VIDEO_H
#define VIDEO_H


class Video
{
	private:
		cv::VideoCapture* cvVideo;

		int nbFrames;
		Frame** frames;

		string path;
		double fps;

		int frameWidth;
		int frameHeight;
		int fourcc;

	private:
		void SetupData();
		void SetupFrames();

	public:
		Video(string path);

		void Display(string windowName);

		void Open();
		void Close();
		void ProcessFrames(bool debug = false);

		const double FPS() { return this->fps; };
		const int Length() { return nbFrames; }

		Frame* GetFrame(int i) { return frames[i]; }

		void Save(string outputPath);
};

#endif // VIDEO_H