#include "Graph.h"

void Graph::Process()
{
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

}
