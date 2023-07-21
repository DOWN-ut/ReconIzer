#include "Frame.h"

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
