#include<stdio.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int list[26];
int dp[26];
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &list[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			int tmax = 1;
			for (int j = 1; j < i; j++)
			{
				if (list[j] >= list[i])
				{
					tmax = max(tmax, dp[j] + 1);
				}
			}
			dp[i] = tmax;
		}
		int ans=1;
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}