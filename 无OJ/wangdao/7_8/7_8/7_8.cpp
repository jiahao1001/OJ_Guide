#include<stdio.h>
#define INF 0x7fffffff
int max(int a, int b)
{
	return a > b ? a : b;
}
struct E{
	int w;
	int v;
}list[101];
int dp[1001];
int main()
{
	int s, n;
	while (scanf("%d%d", &s, &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &list[i].w, &list[i].v);
		}
		for (int i = 0; i <= s; i++)
		{
			dp[i] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = s; j >= list[i].w; j--)
			{
				dp[j] = max(dp[j], dp[j - list[i].w] + list[i].v);
			}
		}
		printf("%d\n", dp[s]);
	}
	return 0;
}
