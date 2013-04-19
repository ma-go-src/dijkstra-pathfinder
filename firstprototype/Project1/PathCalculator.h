#include <list>
#include "Vertex.h"

using namespace std;

public ref class PathCalculator
{
	public:
		PathCalculator();
		list<int> calculatePath(array<Vertex^,1>^ vertexes, int source, int target);
		list<int> arrayToList(array<Vertex^,1>^ vertexes);
		int getSmallestDistanceNode(list<int> setOfNodes, array<int,1>^ dist);
		
	int graphsize;
};