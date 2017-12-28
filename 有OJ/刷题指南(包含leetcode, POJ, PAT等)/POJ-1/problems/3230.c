#include<stdio.h>
#define M	100
#define N	100
int income[M][N],expense[N][N];
int dp[2][N],m,n;
int main()
{
	int i,j,k,max,t;
	while (scanf("%d%d",&n,&m),n!=0 || m!=0)
	{
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				scanf("%d",&expense[i][j]);
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				scanf("%d",&income[i][j]);
		for (i=0;i<n;i++)
			dp[0][i]=income[0][i]-expense[0][i];
		t=0;
		for (i=1;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				max=0;
				for (k=0;k<n;k++)
				{
					if (dp[t][k]+income[i][j]-expense[k][j]>max)
						max=dp[t][k]+income[i][j]-expense[k][j];
				}
				dp[1-t][j]=max;
			}
			t=1-t;
		}
		max=0;
		for (i=0;i<n;i++)
			if (dp[t][i]>max)
				max=dp[t][i];
		printf("%d\n",max);
	}
	return 0;
}
