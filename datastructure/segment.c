#include <stdio.h>
#define NMAX 2000001

int Stree[NMAX] = {0};
int SIZE;

void init(int a[], int s, int e)
{
	SIZE = 2*(e-s+1);
	for(int i = e-s+1; i < SIZE; i++)
		Stree[i] = a[s+i-(e-s+1)];
	for(int i = e-s; i > 0; i--)
		Stree[i] = Stree[2*i]+Stree[2*i+1];
}

void update(int i, int n)
{
	i += SIZE/2-1;
	Stree[i] = n;
	while(i)
	{
		i /= 2;
		Stree[i] += n;
	}
}

int sum(int l, int r)
{
	l += SIZE/2-1;
	r += SIZE/2;
	int sum = 0;
	while(l < r)
	{
		if(l % 2)
			sum += Stree[l++];
		if(r % 2)
			sum += Stree[--r];
		l /= 2;
		r /= 2;
	}
	return sum;
}

void main()
{
	int a[] = {1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5};
	init(a, 0, 13);
	printf("%d\n",sum(1,14));
	update(4, 10);
	printf("%d\n",sum(1,14));
}