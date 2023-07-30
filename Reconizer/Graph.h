#pragma once
#include <opencv2/opencv.hpp>

class Graph
{
protected:
	float* max;
	float* mins;
	float* averages;

	int size;
	cv::Mat* data;

	void Process();

public:
	Graph() {  };
	Graph(cv::Mat* data);

};

