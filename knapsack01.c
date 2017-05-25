#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int dp[1000][1000];

void knapsack(int a[], int b[], int n, int W)
{
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for(int i = 0; i <= W; i++)
		dp[0][i] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= W; j++)
			(b[i-1] > j) ? (dp[i][j] = dp[i-1][j]) : (dp[i][j] = MAX(dp[i-1][j], a[i-1] + dp[i-1][j-b[i-1]]));
}

void main()
{
	int a[] = {1, 2, 5, 9, 4};
	int b[] = {2, 3, 3, 4, 6};
	knapsack(a, b, 5, 10);
	printf("%d\n", dp[5][10]);
}