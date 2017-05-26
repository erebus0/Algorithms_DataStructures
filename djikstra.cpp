#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <list>
#include <climits>
#include <cstdio>

using namespace std;

typedef pair<int, int> intPair;

class Graph
{
	int nOV;
	list<intPair> *adj;
	public:
		Graph(int nOV)
		{
			this->nOV = nOV;
			adj = new list<intPair> [nOV];
		}
		void addEdge(int u, int v, int w)
		{
			adj[v].push_back(make_pair(u, w));
			adj[u].push_back(make_pair(v, w));
		}
		vector<int> shortestPath(int v)
		{
			priority_queue< intPair, vector<intPair>, greater<intPair> > priorityQ;
			priorityQ.push(make_pair(0, v));
			vector<int> distance(nOV, INT_MAX);
			distance[v] = 0;
			while(!priorityQ.empty())
			{
				int u = priorityQ.top().second;
				priorityQ.pop();
				list<intPair>::iterator i;
				for(i = adj[u].begin(); i != adj[u].end(); ++i)
				{
					int su = (*i).first;
					int weight = (*i).second;
					if(distance[su] > distance[u] + weight )
					{
						distance[su] = distance[u] + weight;
						priorityQ.push(make_pair(distance[su], su));
					}
				}
			}
		    return distance;
		}
};

int main()
{
	int V = 6;
    Graph g(V);
    
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 4);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 4, 6);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 4);
    g.addEdge(4, 5, 2);

    vector<int> distance = g.shortestPath(0);

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, distance[i]);
}