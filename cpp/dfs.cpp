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

void dfs(vector< vector<int> > g, int V, int s)
{
	vector<int> v(V, false);
	v[s] = true;
	printf("%d ",s);
	stack<int> S;
	for(auto e: g[s])
		S.push(e);
	while(!S.empty())
	{
		int top = S.top();
		if(!v[top])
		{
			v[top] = true;
			printf("%d ", top);
			S.pop();
			for(auto e: g[top])
				S.push(e);
		}
		else
			S.pop();
	}
	printf("\n");
}

int main()
{
	vector< vector<int> > graph = make_graph(5);
	make_edge(graph, 0, 1);
	make_edge(graph, 0, 2);
	make_edge(graph, 1, 3);
	make_edge(graph, 4, 3);
	dfs(graph, 5, 0);
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