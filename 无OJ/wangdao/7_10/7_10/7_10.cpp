#include<stdio.h>
struct E{
	int w;
	int v;
}list[2001];
int dp[101];
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int s, n;
		scanf("%d%d", &s, &n);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			int v, w, k;
			scanf("%d%d%d", &w, &v, &k);
			int c = 1;
			while (k - c > 0)
			{
				k -= c;
				list[++cnt].w = c*w;
				list[cnt].v = c*v;
				c *= 2;
			}
			list[++cnt].w = w*k;
			list[cnt].v = v*k;
		}
		for (int i = 1; i <= s; i++)
			dp[i] = 0;
		for (int i = 1; i <= cnt; i++)
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