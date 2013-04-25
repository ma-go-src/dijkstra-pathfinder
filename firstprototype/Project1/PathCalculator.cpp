#include "PathCalculator.h"
#include <iostream>
#include <list>

#define INFINITY 2147483647
#define UNDEFINED 0

using namespace std;

PathCalculator::PathCalculator()
{
	
}

list<int> PathCalculator::calculatePath(array<Vertex^,1>^ vertexes, int source, int target)
{
	graphsize = vertexes->Length;
	list<int> path;

	int* previous = new int[graphsize];
	list<int> setOfNodes = arrayToList(vertexes);

	array<int,1>^ dist = gcnew array<int, 1>(graphsize);

	for (int q = 0; q < graphsize; q++)
	{
		dist[q] = INFINITY;
		previous[q] = UNDEFINED;
	}
	dist[source] = 0;

	int u;		//node with smallest value
	int alt;
	int distanceToNext = 0;

	while (!setOfNodes.empty())
	{
		u = getSmallestDistanceNode(setOfNodes, dist);
		setOfNodes.remove(vertexes[u]->GetID());

		for (int z = 0; z < vertexes[u]->GetNeighborsArray()->Length; z++)
		{
			if(!vertexes[u]->GetNeighborsArray()[z]->IsVisited())
			{
				vertexes[u]->GetNeighborsArray()[z]->SetWorking();
				alt = dist[u] + distanceToNext;	// distance between each node = 1

				if (alt < dist[vertexes[u]->GetNeighborsArray()[z]->GetID() - 1])
				{
					dist[vertexes[u]->GetNeighborsArray()[z]->GetID() - 1] = alt;
					previous[vertexes[u]->GetNeighborsArray()[z]->GetID() - 1] = u;
				}
			}
		}

		path.push_back(u);
		vertexes[u]->SetDone(alt);

		if (u == target)
		{
			int actualNode = u;
			while (actualNode != source)
			{
				actualNode = previous[actualNode];
				vertexes[actualNode]->SetPath(true);
			}

			break;
		}

		distanceToNext = 1;
	}

	return path;
}

list<int> PathCalculator::arrayToList(array<Vertex^,1>^ vertexes)
{
	list<int> setOfNodes;

	for (int q = 0; q < vertexes->Length; q++)
	{
		setOfNodes.push_back(vertexes[q]->GetID());
	}

	return setOfNodes;
}

int PathCalculator::getSmallestDistanceNode(list<int> setOfNodes, array<int,1>^ dist)
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