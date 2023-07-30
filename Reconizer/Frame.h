#pragma once
#include <opencv2/opencv.hpp>
#include "Graph.h"

using namespace std;

#ifndef FRAME_H
#define FRAME_H
class Frame
{
protected:
	cv::Mat data;
	string name;

	Graph* graph;

public:
	cv::Mat Image() { return data; }
	void SetImage(cv::Mat m) { data = m; }
	Graph* GetGraph() { return graph; }

	void Process();
	void Show() { cv::imshow(name, Image()); }

	Frame();
	Frame(int frameId, cv::Mat arr);
	Frame(string name, cv::Mat arr);
};

#endif