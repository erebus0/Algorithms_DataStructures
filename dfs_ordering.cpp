#include <cstdio>
#include <vector>

using namespace std;

/* This code straightens a tree into an array such that each node has all its decendents as a subarray starting at that node. Useful for queries on nodes and subtrees.*/

void dfs_order(vector < vector< int > > &graph, vector < int > &visited, vector < int > &preorder, vector < int > &position, vector < int > &no_of_children, int node) {
	position[node] = preorder.size();
	preorder.push_back(node);
	visited[node] = 1;
	for(int i = 0; i < graph[node].size(); i++) {
		if(visited[graph[node][i]] != 1) {
			dfs_order(graph, visited, preorder, position, no_of_children, graph[node][i]);
			no_of_children[node] += (no_of_children[graph[node][i]] + 1);
		}
	}
}

int main()
{
	vector < vector < int > > graph{ {1, 2}, {3, 4}, {5}, {}, {}, {} };
	vector < int > visited(6);
	vector < int > position(6);
	vector < int > no_of_children(6, 0);
	vector < int > preorder(0);
	dfs_order(graph, visited, preorder, position, no_of_children, 0);
	for(int i = 0; i < 6; i++) printf("%d ", preorder[i]);
	printf("\n");
	for(int i = 0; i < 6; i++) printf("%d ", position[i]);
	printf("\n");
	for(int i = 0; i < 6; i++) printf("%d ", no_of_children[i]);
	printf("\n");
	return 0;
}
