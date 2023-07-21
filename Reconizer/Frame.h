#pragma once
#include <opencv2/opencv.hpp>

using namespace std;

class Frame
{
protected:
	cv::_OutputArray data;
	string name;

public:
	cv::Mat Image() { data.getMat(); }

	void Show() { imshow(name, Image()); }

	Frame(int frameId, cv::_OutputArray arr);
	Frame(string name, cv::_OutputArray arr);
};

