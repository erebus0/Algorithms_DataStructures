#include <bits/stdc++.h>

using namespace std;

void make_edge(vector< vector< pair<int, int> > > &g, int n1, int n2, int w)
{
    g[n1].push_back(make_pair(n2, w));
    g[n2].push_back(make_pair(n1, w));
}

void delete_edge(vector< vector< pair<int, int> > > &g, int n1, int n2)
{
    g[n1].erase(g[n1].find(g[n1].begin(), g[n1].end(), ))
}

vector< vector< pair<int, int> > > make_graph( int V)
{
    return vector< vector< pair<int, int> > >(V);
}

void print_adj_list(vector< vector< pair<int, int> > > g, int V)
{
    int i = 0;
    for(auto l: g)
    {
        printf("%d ", i++);
        for(auto n: l)
            printf("%d-%d\t", n.first, n.second);
        printf("\n");
    }
}

int main() {
	vector< vector< pair<int, int> > > graph = make_graph(5);
	make_edge(graph, 0, 1, 5);
	make_edge(graph, 0, 2, 9);
	make_edge(graph, 1, 3, 4);
	make_edge(graph, 0, 3, 2);
	make_edge(graph, 4, 1, 8);
	
	print_adj_list(graph, 5);
	return 0;
}
