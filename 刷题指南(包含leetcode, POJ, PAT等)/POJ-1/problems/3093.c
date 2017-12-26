#include<stdio.h>
#include<string.h>
#include<stdlib.h>
__int64 price[30],sum[30];
unsigned int g[1100][40];
int cmp(const void *a, const void *b)
{
	__int64 x,y;
	x=*(__int64 *)a;
	y=*(__int64 *)b;
	if (x<y)
		return -1;
	else if (x>y)
		return 1;
	else return 0;
}
int main()
{
	int i,j,k,n,v,d;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&v,&d);
		for (j=0;j<v;j++)
			scanf("%I64d",&price[j]);
		qsort(price,v,sizeof(price[0]),cmp);
		for (sum[0]=price[0],j=1;j<v;j++)
			sum[j]=sum[j-1]+price[j];
		memset(g,0,sizeof(g));
		for (k=0;k<=d;k++)
			g[k][0]=1;
		for (j=1;j<v;j++)
		{
			for (k=0;k<=d;k++)
			{
				if (k<price[j])
					g[k][j]=g[k][j-1];
				else if (k<sum[j])
					g[k][j]=g[k][j-1]+g[k-price[j]][j-1];
				else g[k][j]=1;
			}
		}
		if (d<price[0])
			g[d][v-1]=0;
		printf("%d %u\n",i,g[d][v-1]);
	}
	return 0;
}
