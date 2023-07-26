#pragma once
#include <opencv2/opencv.hpp>

using namespace std;

class Frame
{
protected:
	cv::Mat data;
	string name;

public:
	cv::Mat Image() { return data; }

	void Show() { cv::imshow(name, Image()); }

	Frame();
	Frame(int frameId, cv::Mat arr);
	Frame(string name, cv::Mat arr);
};

