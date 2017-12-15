#include <stdio.h>

void merge(int a[], int l, int m, int r)
{
	int i, j, k;
	int l1 = m - l + 1;
	int l2 = r - m;
	int L1[l1], L2[l2];
	for(i = 0; i<l1; i++)
		L1[i] = a[l + i];
	for(i = 0; i<l2; i++)
		L2[i] = a[m + 1 + i];
	k = l;
	i = 0;
	j = 0;
	while(i < l1 && j < l2)
	{
		if(L1[i] <= L2[j])
			a[k] = L1[i++];
		else
			a[k] = L2[j++];
		k++;
	}
	while(i < l1)
		a[k++] = L1[i++];
	while(j < l2)
		a[k++] = L2[j++];
}

void merge_sort(int a[], int l, int r)
{
	int m;
	if(l < r)
	{
		m = l + (r - l)/2;
		merge_sort(a, l, m);
		merge_sort(a, m+1, r);
		merge(a, l, m, r);
	}
}

int main()
{
	int a[100], i;
	int n;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
		scanf("%d", a+i);
	merge_sort(a, 0, n-1);
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}