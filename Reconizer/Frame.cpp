#include "Frame.h"

Frame::Frame()
{
	this->data = cv::Mat();
}

Frame::Frame(int frameId, cv::Mat arr)
{
	this->name = frameId;
	this->data = arr;
}

Frame::Frame(string name, cv::Mat arr)
{
	this->name = name;
	this->data = arr;
}
