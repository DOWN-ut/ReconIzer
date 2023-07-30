#include "Graph.h"

void Graph::Process()
{
}

bool Graph::Compare(Graph* over)
{
	for (int i = 0; i < size; i++)
	{
		bool maxok = MaxAt(i) <= over->MaxAt(i);
	}
}

Graph::Graph(cv::Mat* data)
{

}
