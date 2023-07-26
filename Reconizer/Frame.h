#pragma once
#include <opencv2/opencv.hpp>

using namespace std;

#ifndef FRAME_H
#define FRAME_H
class Frame
{
protected:
	cv::Mat data;
	string name;

public:
	cv::Mat Image() { return data; }
	void SetImage(cv::Mat m) { data = m; }

	void Show() { cv::imshow(name, Image()); }

	Frame();
	Frame(int frameId, cv::Mat arr);
	Frame(string name, cv::Mat arr);
};

#endif