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
	
	//list<int> neighbourhoods[sizeof(graph)];	// to fill

	int* previous = new int[graphsize];
	list<int> setOfNodes = arrayToList(vertexes);

	array<int,1>^ dist = gcnew array<int, 1>(graphsize);
	//int dist[graphsize];

	for (int q = 0; q < graphsize; q++)
	{
		dist[q] = INFINITY;
		previous[q] = UNDEFINED;
	}
	dist[source] = 0;

	int u;		//node with smallest value
	list<int>::iterator i;
	int alt;

	int distanceToNext = 0;

	while (!setOfNodes.empty())
	{
		u = getSmallestDistanceNode(setOfNodes, dist);
		setOfNodes.remove(vertexes[u]->GetID());

		//for (i = neighbourhood[u].begin(); i != neighbourhoods[u].end(); ++i)
		for (int z = 0; z < vertexes[u]->GetNeighborsArray()->Length; z++)
		{
			if(!vertexes[u]->GetNeighborsArray()[z]->IsVisited()){
			vertexes[u]->GetNeighborsArray()[z]->SetWorking();
			alt = dist[u] + distanceToNext;	// distance between each node = 1
			if (alt < dist[vertexes[u]->GetNeighborsArray()[z]->GetID() - 1])
			{
				dist[vertexes[u]->GetNeighborsArray()[z]->GetID() - 1] = alt;
				previous[vertexes[u]->GetNeighborsArray()[z]->GetID() - 1] = u;
			}
			cout<<"FOR OK"<<endl;
			}}

		path.push_back(u);
		vertexes[u]->SetDone(alt);	// still to test
		if (u == target)
			break;

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