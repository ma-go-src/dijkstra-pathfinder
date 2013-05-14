#include <list>
#include "Vertex.h"

using namespace std;

public ref class PathCalculator
{
	public:
		PathCalculator();
		void calculatePath(array<Vertex^,1>^ vertexes, int source, int target, int mSec);
		list<int> arrayToList(array<Vertex^,1>^ vertexes);
		int getSmallestDistanceNode(list<int> setOfNodes, array<int,1>^ dist);
		int dist_between(array<Vertex^,1>^ vertexes, int node1, int node2);
		bool IsDiagonalUnpassable(int node, int neigh);
		array<Vertex^,1>^ vertexes;
	int graphsize;
};