#include "Graph.h"

void Graph::Process()
{
	cv::Vec3f max;
	cv::Vec3f min;
	cv::Vec3f currentPixel;

	for (int i = 0; i < this->data->cols; i++) {
		cv::Vec3f max = cv::Vec3f(0, 0, 0);
		cv::Vec3f min = cv::Vec3f(0, 0, 0);

		for (int j = 0; j < this->data->rows; j++)
		{
			currentPixel = data->at<cv::Vec3b>(j, i);
			for (int c = 0; c < 3; c++) {
				if (max[c] < currentPixel[c]) { max[c] = currentPixel[c]; }
				if (min[c] > currentPixel[c]) { min[c] = currentPixel[c]; }
			}
		}

		mins[i] = min;
		maxs[i] = max;
	}
}

bool Graph::Compare(Graph* over, int position)
{
	for (int i = 0; i < size && position + i < over->size; i++)
	{
		for (int c = 0; c < 3; c++) 
		{
			if (!(
				MaxAt(i)[c] <= over->MaxAt(position + i)[c] &&
				MinAt(i)[c] >= over->MinAt(position + i)[c]))
			{
				return false;
			}
		}
	}
	return true;
}

Graph::Graph(cv::Mat* data)
{
	this->data = data;
	this->size = data->cols;
	this->mins = new cv::Vec3f[size];
	this->maxs = new cv::Vec3f[size];
	this->Process();
}
