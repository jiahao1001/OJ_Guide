#include<stdio.h>
short greedy[100000];
int main()
{
	int n,i,max;
	__int64 sum;
	scanf("%d",&n);
	while (n!=0)
	{
		for (i=0;i<n;i++)
			scanf("%d",&greedy[i]);
		sum=0;
		max=0;
		for (i=0;i<n;i++)
		{
			max+=greedy[i];
			if (max>0)
				sum+=max;
			else sum-=max;
		}
		printf("%I64d\n",sum);
		scanf("%d",&n);
	}
	return 0;
}
