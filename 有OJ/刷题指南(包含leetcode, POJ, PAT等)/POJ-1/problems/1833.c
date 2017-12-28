#include <stdio.h>
int main()
{
	int i,j,k,m,n,q;
	int p[1024],a,b,c,temp;
	scanf("%d",&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d %d",&n,&q);
		for (j=0;j<n;j++)
			scanf("%d",&p[j]);
		for (k=1;k<=q;k++)
		{
			for (a=n-1;a>0;a--)
			{
				if (p[a-1]<p[a])
					break;
			}
			if (a!=0)
			{
				for (b=n-1;b>=0;b--)
				{
					if (p[a-1]<p[b])
						break;
				}
				temp=p[a-1];
				p[a-1]=p[b];
				p[b]=temp;
			}
			for (c=a;c<(a+n)/2;c++)
			{
				temp=p[c];
				p[c]=p[n+a-c-1];
				p[n+a-c-1]=temp;
			}
		}
		for (j=0;j<n-1;j++)
			printf("%d ",p[j]);
		printf("%d\n",p[j]);
	}
	return 0;
}
