#include <stdio.h>
#define NMAX 1000000

int BItree[NMAX] = {0};
int SIZE;

int sum(int i)
{
	int sum = BItree[i];
	while(i)
	{
		i -= (i & (-i));
		sum += BItree[i];
	}
	return sum;
}

void add(int i, int a)
{
	while(i < SIZE)
	{
		BItree[i] += a;
		i += (i & (-i));
	}
}

void init(int a[], int s, int e)
{
	SIZE = e-s+2;
	for(int i = 1; i <= e-s+2; i++)
		add(i, a[s+i-1]);
}

void main()
{
	int a[] = {1,7,3,0,5,8,3,2,6,2,1,1,4,5};
	init(a,0,13);
	printf("%d\n",sum(14));
	add(4,7);
	printf("%d\n",sum(14));
}