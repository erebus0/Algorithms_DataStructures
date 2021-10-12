#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void swap(int &a1, int &a2) {
	a1 += a2;
	a2 = a1 - a2;
	a1 = a1 - a2;
}

void heapify(pair< int, vector< int > > &heap, int index) {
	if(heap.second[index] > heap.second[index/2] && index != 1) {
		swap(heap.second[index], heap.second[index/2]);
		heapify(heap, index/2);
	}
}

int extract(pair< int, vector< int > > &heap) {
	int ans = heap.second[1];
	heap.second[1] = heap.second[heap.first];
	heap.second[heap.first] = -1;
	heap.first--;
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the number of elements you want");
	scanf("%d", &n);
	pair< int, vector< int > > heap = make_pair(0, vector< int >(100001, -1));
	for(int i = 0; i<n; i++) {
		printf("Enter the %d number\n", i+1);
		scanf("%d", &heap.second[i+1]);
		heapify(heap, i+1);
	}
	for(int i = 0; i < n; i++) printf("%d ", heap.second[i+1]); printf("\n");
	return 0;
}