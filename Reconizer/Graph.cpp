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

			this->teintes[i][(int)ImageOpperations::ToHSL(currentPixel)[0]]++;

			for (int c = 0; c < 3; c++) 
			{
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
		int count = 0; int total = 0;
		for (int c = 0; c < 360; c++)
		{
			//if (teintes[i][c] > 0 && over->teintes[position+i][c] <= 0) { return false; }
			if (teintes[i][c] > 0) 
			{ 
				total++; 
				if (over->teintes[position + i][c] > 0)
				{
					count++;
				}
			}
		}
		float r = count / (float)(total);
		if (r < 0.1f) { return false; }
	}
	return true;
}

void Graph::Display()
{
	for (int i = 0; i < size; i++)
	{
		//cout << MaxAt(i)[0] << "-" << MinAt(i)[0] << endl;
		for (int c = 0; c < 360; c++)
		{
			if (teintes[i][c] > 0) { cout << c << " "; }
		}
		cout << endl;
	}
}

Graph::Graph(cv::Mat* data)
{
	this->data = data;
	this->size = data->cols;
	this->mins = new cv::Vec3f[size];
	this->maxs = new cv::Vec3f[size];
	this->teintes = new int*[size];
	for (int i = 0; i < size; i++) { this->teintes[i] = new int[360]; for (int c = 0; c < 360; c++) { this->teintes[i][c] = 0; } }
	this->Process();
}
