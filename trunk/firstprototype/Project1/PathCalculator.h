#include <list>

using namespace std;

public ref class PathCalculator
{
	//typedef std::list<int> IntList;

	public:
		PathCalculator();
		list<int> calculatePath(int graph[], int source, int target);
		list<int> arrayToList(int graph[]);
		int getSmallestDistanceNode(list<int> setOfNodes, int dist[]);
		
	int graphsize;
};