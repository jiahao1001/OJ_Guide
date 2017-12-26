#include<stdio.h>
#include<math.h>
int n,k,dry[100000];
int bin(int t)
{
	int i;
	__int64 total=0;
	for (i=0;i<n;i++)
	{
		if (dry[i]>t)
			total+=(int)ceil(((double)(dry[i]-t))/(k-1));
	}
	if (total>t)
		return 0;
	return 1;
}
int main()
{
	int low,high,mid,i;
	scanf("%d",&n);
	low=0;
	high=0;
	for (i=0;i<n;i++)
	{
		scanf("%d",&dry[i]);
		if (dry[i]>high)
			high=dry[i];
	}
	scanf("%d",&k);
	if (k!=1)
	{
		while (high-low>1)
		{
			mid=(high+low)/2;
			if (bin(mid)==0)
				low=mid;
			else high=mid;
		}
	}
	printf("%d\n",high);
	return 0;
}
