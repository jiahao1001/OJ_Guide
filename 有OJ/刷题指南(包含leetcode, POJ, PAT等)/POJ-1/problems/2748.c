#include<stdio.h>
int dp[75001]={0,1,2};
int main()
{
	int i,n,m;
	for (i=3;i<75001;i++)
	{
		dp[i]=3*dp[i-1]-dp[i-2];
		if (dp[i]<0)
			dp[i]+=100000;
		dp[i]%=100000;
	}
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&m);
		m%=75000;
		if (m==0)
			m=75000;
		printf("%d\n",dp[m]);
	}
	return 0;
}
