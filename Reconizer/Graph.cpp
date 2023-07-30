#include "Graph.h"

void Graph::Process()
{
}

bool Graph::Compare(Graph* over, int position)
{
	for (int i = 0; i < size && position + i < over->size; i++)
	{
		if (!(
			MaxAt(i) <= over->MaxAt(position + i) &&
			MinAt(i) >= over->MinAt(position + i)))
		{
			return false;
		}
	}
	return true;
}

Graph::Graph(cv::Mat* data)
{

}
