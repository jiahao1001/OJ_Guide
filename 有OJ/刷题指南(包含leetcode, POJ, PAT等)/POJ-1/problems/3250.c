#include<stdio.h>
int n,hair[80000],dp[80000]={0};
int link[80000]={0};
int main()
{
	int i,j;
	__int64 sum=0;
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&hair[i]);
	for (i=n-2;i>=0;i--)
	{
		for (j=i+1;j>0 && hair[i]>hair[j];j=link[j])
		{
			dp[i]=dp[i]+dp[j]+1;
		}
		if (j>0)
			link[i]=j;
		sum+=dp[i];
	}
	printf("%I64d\n",sum);
	return 0;
}
