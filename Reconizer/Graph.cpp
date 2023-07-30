#include "Graph.h"
#include "ImageOpperations.h"

void Graph::Process()
{
	cv::Vec3f max;
	cv::Vec3f min;
	cv::Vec3f currentPixel;

	for (int i = 0; i < this->data->cols; i++) {
		max = cv::Vec3f(0, 0, 0);
		min = cv::Vec3f(1000, 1000, 1000);
		
		for (int j = 0; j < this->data->rows; j++)
		{
			currentPixel = data->at<cv::Vec3b>(j, i);
			this->teintes[(int)ImageOpperations::ToHSL(currentPixel)[0]]++;
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
		/*for (int c = 0; c < 3; c++)
		{
			if (!(
				MaxAt(i)[c] <= over->MaxAt(position + i)[c] &&
				MinAt(i)[c] >= over->MinAt(position + i)[c]))
			{
				return false;
			}
		}*/
		for (int c = 0; c < 360; c++)
		{
			if (teintes[c] > 0 && over->teintes[c] <= 0) { return false; }
		}
	}
	return true;
}

void Graph::Display()
{
	for (int i = 0; i < size; i++)
	{
		cout << MaxAt(i)[0] << "-" << MinAt(i)[0] << endl;
	}
}

Graph::Graph(cv::Mat* data)
{
	this->data = data;
	this->size = data->cols;
	this->mins = new cv::Vec3f[size];
	this->maxs = new cv::Vec3f[size];
	this->Process();
}
