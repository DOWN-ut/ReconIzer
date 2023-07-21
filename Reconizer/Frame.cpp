#include "Frame.h"

Frame::Frame(int frameId, cv::_OutputArray arr)
{
	this->name = frameId;
	this->data = arr;
}

Frame::Frame(string name, cv::_OutputArray arr)
{
	this->name = name;
	this->data = arr;
}
