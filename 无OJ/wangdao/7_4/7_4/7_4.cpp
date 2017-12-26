#include<stdio.h>
#include<string.h>
int dp[101][101];
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	char S1[101], S2[101];
	while (scanf("%s%s", S1, S2) != EOF)
	{
		int L1 = strlen(S1);
		int L2 = strlen(S2);
		for (int i = 0; i <= L1; i++)
			dp[i][0] = 0;
		for (int j = 0; j <= L2; j++)
			dp[0][j] = 0;
		for (int i = 1; i <= L1; i++)
		{
			for (int j = 1; j <= L2; j++)
			{
				if (S1[i - 1] != S2[j - 1])
				{
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
		}
		printf("%d\n", dp[L1][L2]);
	}
	return 0;
}