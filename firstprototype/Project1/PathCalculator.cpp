#include "PathCalculator.h"
#include <iostream>
#include <list>

#define INFINITY 2147483647
#define UNDEFINED 0

using namespace std;

PathCalculator::PathCalculator()
{
	
}

list<int> PathCalculator::calculatePath(int graph[], int source, int target)
{
	graphsize = sizeof(graph);
	list<int> path;
	
	list<int> neighbourhoods[sizeof(graph)];	// to fill

	int* previous = new int[graphsize];
	list<int> setOfNodes = arrayToList(graph);

	int dist[sizeof(graph)];

	for (int q = 0; q < graphsize; q++)
	{
		dist[q] = INFINITY;
		previous[q] = UNDEFINED;
	}
	dist[source] = 0;

	int u;		//node with smallest value
	list<int>::iterator i;
	int alt;

	while (!setOfNodes.empty())
	{
		u = getSmallestDistanceNode(setOfNodes, dist);
		setOfNodes.remove(graph[u]);

		for (i = neighbourhoods[u].begin(); i != neighbourhoods[u].end(); ++i)
		{
			alt = dist[u] + 1;	// distance between each node = 1
			if (alt < dist[*i - 1])
			{
				dist[*i - 1] = alt;
				previous[*i - 1] = u;
			}
		}

		path.push_back(u);
		if (u == target)
			break;
	}

	return path;
}

list<int> PathCalculator::arrayToList(int graph[])
{
	list<int> setOfNodes;

	for (int q = 0; q < sizeof(graph); q++)
	{
		setOfNodes.push_back(graph[q]);
	}

	return setOfNodes;
}

int PathCalculator::getSmallestDistanceNode(list<int> setOfNodes, int dist[])
{
	int smallestDistance = INFINITY;
	int node;

	list<int>::iterator i;
	for (i = setOfNodes.begin(); i != setOfNodes.end(); ++i)
	{
		if (dist[*i - 1] < smallestDistance)
		{
			smallestDistance = dist[*i - 1];
			node = *i - 1;
		}
	}

	return node;
}