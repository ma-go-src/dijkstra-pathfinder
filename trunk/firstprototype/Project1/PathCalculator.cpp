#include "PathCalculator.h"
#include <iostream>
#include <list>

#define INFINITY 2147483647
#define UNDEFINED 0

using namespace std;

PathCalculator::PathCalculator()
{

}

void PathCalculator::calculatePath(array<Vertex^,1>^ vertexArray, int source, int target, int mSec)
{
	vertexes = vertexArray;
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

	while (!setOfNodes.empty())
	{
		_sleep(mSec);

		u = getSmallestDistanceNode(setOfNodes, dist);
		
		if(u != -1){
			setOfNodes.remove(vertexes[u]->GetID());
			for (int z = 0; z < vertexes[u]->GetNeighborsArray()->Length; z++)
			{
				if(!vertexes[u]->GetNeighborsArray()[z]->IsVisited() && !vertexes[u]->GetNeighborsArray()[z]->IsWall()
					&& !IsDiagonalUnpassable(u, z))
				{
					vertexes[u]->GetNeighborsArray()[z]->SetWorking();
					alt = dist[u] + dist_between(vertexes, u, z);

					if (alt < dist[vertexes[u]->GetNeighborsArray()[z]->GetID() - 1])
					{
						dist[vertexes[u]->GetNeighborsArray()[z]->GetID() - 1] = alt;
						previous[vertexes[u]->GetNeighborsArray()[z]->GetID() - 1] = u;
					}
				}
			}

			vertexes[u]->SetDone(alt);}
		else 
			break;

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


	}
	if(u == -1)
		cout << "No Path";
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
	int node = -1;

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

bool PathCalculator::IsDiagonalUnpassable(int node, int neigh)
{
	bool isUnpassable = false;
	
	if (vertexes[node]->GetNeighborsArray()->Length == 3)
	{
		
	}
	else if (vertexes[node]->GetNeighborsArray()->Length == 5)
	{

	}
	else
	{
		if (neigh == 3 && vertexes[node]->GetNeighborsArray()[2]->IsWall() && vertexes[node]->GetNeighborsArray()[0]->IsWall())
			isUnpassable = true;
		else if (neigh == 4 && vertexes[node]->GetNeighborsArray()[2]->IsWall() && vertexes[node]->GetNeighborsArray()[1]->IsWall())
			isUnpassable = true;
		else if (neigh == 6 && vertexes[node]->GetNeighborsArray()[0]->IsWall() && vertexes[node]->GetNeighborsArray()[5]->IsWall())
			isUnpassable = true;
		else if (neigh == 7 && vertexes[node]->GetNeighborsArray()[5]->IsWall() && vertexes[node]->GetNeighborsArray()[1]->IsWall())
			isUnpassable = true;
	}

	return isUnpassable;
}