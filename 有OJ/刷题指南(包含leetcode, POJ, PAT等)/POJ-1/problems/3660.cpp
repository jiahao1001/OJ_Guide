#include<stdio.h>
#define MAX 100
bool Dist[MAX][MAX]={false};
int N,M,degree[MAX]={0};
void Floyd_Warshall(int n)//n为实际结点数
{
	int i,j,k;
	for (k=0;k<n;k++)
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
					Dist[i][j]=Dist[i][j] || (Dist[i][k] && Dist[k][j]);
}
int main()
{
	int i,j,a,b;
	scanf("%d%d",&N,&M);
	for (i=0;i<M;i++)
	{
		scanf("%d%d",&a,&b);
		Dist[a-1][b-1]=true;
	}
	Floyd_Warshall(N);
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (Dist[i][j]==true)
			{
				degree[i]++;
				degree[j]++;
			}
		}
	}
	for (i=0,j=0;i<N;i++)
		if (degree[i]==N-1)
			j++;
	printf("%d\n",j);
	return 0;
}
