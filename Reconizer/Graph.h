#pragma once
#include <opencv2/opencv.hpp>

class Graph
{
protected:
	cv::Vec3f* maxs;
	cv::Vec3f* mins;
	cv::Vec3f* averages;

	int size;
	cv::Mat* data;

	void Process();

	bool Compare(Graph* over, int position);

public:
	Graph() {  };
	Graph(cv::Mat* data);

	cv::Vec3f MaxAt(int i) { return maxs[i]; }
	cv::Vec3f MinAt(int i) { return mins[i]; }
	cv::Vec3f AverageAt(int i) { return averages[i]; }
};
