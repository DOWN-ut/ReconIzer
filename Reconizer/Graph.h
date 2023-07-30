#pragma once
#include <opencv2/opencv.hpp>

class Graph
{
protected:
	float* maxs;
	float* mins;
	float* averages;

	int size;
	cv::Mat* data;

	void Process();

	bool Compare(Graph* over);

public:
	Graph() {  };
	Graph(cv::Mat* data);

	float MaxAt(int i) { return maxs[i]; }
	float MinAt(int i) { return mins[i]; }
	float AverageAt(int i) { return averages[i]; }
};

