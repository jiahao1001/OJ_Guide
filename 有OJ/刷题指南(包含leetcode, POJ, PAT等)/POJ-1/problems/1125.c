#include<stdio.h>
#include<string.h>
#define MAX 100
int Dist[MAX][MAX],n;
void Floyd_Warshall(int n)
{
	int i,j,k;
	for (k=0;k<n;k++)
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (Dist[i][k]!=0 && Dist[k][j]!=0 && (Dist[i][j]==0 || Dist[i][k]+Dist[k][j]<Dist[i][j]))
					Dist[i][j]=Dist[i][k]+Dist[k][j];
}
int main()
{
	int i,j,k,a,b,m;
	scanf("%d",&n);
	while (n!=0)
	{
		memset(Dist,0,sizeof(Dist));
		for (i=0;i<n;i++)
		{
			scanf("%d",&m);
			for (j=0;j<m;j++)
			{
				scanf("%d%d",&a,&b);
				Dist[i][a-1]=b;
			}
		}
		Floyd_Warshall(n);
		for (i=0,a=10000;i<n;i++)
		{
			for (j=0,k=0;j<n;j++)
			{
				if (i==j)
					continue;
				if (Dist[i][j]==0)
					break;
				if (Dist[i][j]>k)
					k=Dist[i][j];
			}
			if (j==n && k!=0 && k<a)
				a=k,b=i+1;
		}
		if (a==10000)
			printf("disjoint\n");
		else printf("%d %d\n",b,a);
		scanf("%d",&n);
	}
	return 0;
}
