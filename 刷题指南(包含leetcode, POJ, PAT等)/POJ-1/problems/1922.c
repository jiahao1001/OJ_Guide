#include<stdio.h>
int main()
{
	int n,i,j,s=16200,m,t,v;
	scanf("%d",&n);
	while (n)
	{
		m=16201;
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&v,&t);
			if (t>=0 && (j=t+s/v)<m)
				m=j+(s%v==0 ? 0:1);
		}
		printf("%d\n",m);
		scanf("%d",&n);
	}			
	return 0;
}
