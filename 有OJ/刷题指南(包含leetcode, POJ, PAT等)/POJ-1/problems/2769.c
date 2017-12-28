#include<stdio.h>
#include<string.h>
int main()
{
	int n,m,i,k,x,s,d[300];
	char f[40000]={0};
	scanf("%d",&x);
	for (k=0;k<x;k++)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%d",&d[i]);
		m=n;
		while (1)
		{
			for (i=0;i<n;i++)
			{
				s=d[i]%m;
				if (f[s]==1)
					break;
				f[s]=1;
			}
			if (i==n)
			{
				printf("%d\n",m);
				break;
			}
			memset(f,0,m);
			m++;
		}
		memset(f,0,m);	
	}
	return 0;
}
