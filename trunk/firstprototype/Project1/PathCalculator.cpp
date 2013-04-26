#include "PathCalculator.h"
#include <iostream>
#include <list>

#define INFINITY 2147483647
#define UNDEFINED 0

using namespace std;

PathCalculator::PathCalculator()
{
	
}

void PathCalculator::calculatePath(array<Vertex^,1>^ vertexes, int source, int target)
{
	graphsize = vertexes->Length;

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
				//TEST
				/*if (vertexes[u]->GetNeighborsArray()[z]->GetXCoordinate() != vertexes[u]->GetXCoordinate() 
					&& vertexes[u]->GetNeighborsArray()[z]->GetYCoordinate() != vertexes[u]->GetYCoordinate())
				{
					distanceToNext = 3;
				}*/
				//TEST
				alt = dist[u] + dist_between(vertexes, u, z);	// distance between each node = 2

				if (alt < dist[vertexes[u]->GetNeighborsArray()[z]->GetID() - 1])
				{
					dist[vertexes[u]->GetNeighborsArray()[z]->GetID() - 1] = alt;
					previous[vertexes[u]->GetNeighborsArray()[z]->GetID() - 1] = u;
				}
			}
		}

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

		//distanceToNext = 2;
	}
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

int PathCalculator::dist_between(array<Vertex^,1>^ vertexes, int node1, int node2)
{
	if (vertexes[node1]->GetNeighborsArray()[node2]->GetXCoordinate() != vertexes[node1]->GetXCoordinate() 
		&& vertexes[node1]->GetNeighborsArray()[node2]->GetYCoordinate() != vertexes[node1]->GetYCoordinate())
	{
		return 3;
	}
	else
		return 2;
}