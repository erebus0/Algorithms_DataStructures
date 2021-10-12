#include <bits/stdc++.h>

using namespace std;

void make_edge(vector< vector<int> > &g, int n1, int n2)
{
    g[n1].push_back(n2);
    g[n2].push_back(n1);
}

vector< vector<int> > make_graph(int noOfVertex)
{
    return vector< vector<int> >(noOfVertex, vector<int>(0,0));
}

void bfs(vector< vector<int> > g, int V, int s)
{
    vector< bool > v(V, false);
    queue< int > q;
    v[s] = true;
    printf("%d ", s);
    for(auto n: g[s])
    {
        q.push(n);
        v[n] = true;
    }
    while(!q.empty())
    {
        int ne = q.front();
        printf("%d ", ne);
        for(auto n: g[ne])
            if(!v[n])
            {
                q.push(n);
                v[n] = true;
            }
        q.pop();
    }
    printf("\n");
}

int main() {
	vector< vector<int> > graph = make_graph(5);
	make_edge(graph, 0, 1);
	make_edge(graph, 0, 2);
	make_edge(graph, 1, 3);
	make_edge(graph, 0, 3);
	make_edge(graph, 4, 1);
	
	bfs(graph,5, 1);
	
	for(auto d: graph)
	{
	    for(auto n: d)
	    {
	        printf("%d ", n);
	    }
	    printf("\n");
	}
	return 0;
}