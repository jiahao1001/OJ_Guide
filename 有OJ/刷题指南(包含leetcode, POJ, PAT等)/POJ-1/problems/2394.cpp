#include<stdio.h>
#define MAX 500
#define MAXVALUE 100000000//表示两点之间无边连通
int Cost[MAX][MAX],Dist[MAX],Prev[MAX];
void Dijkstra(int n,int v)//求n个结点的图中(邻接矩阵存储),顶点v到其他各点的最短路径,Dist数组保存最短路径的值,Prev数组保存路径
{
	int newdist,i,j,temp,u;
	bool s[MAX];
	for(i=0;i<n;i++)
	{
		Dist[i]=Cost[v][i];
		s[i]=false;
		if (Dist[i]==MAXVALUE)
			Prev[i]=0;
		else Prev[i]=v;
	}
	Dist[v]=0;
	s[v]=true;
	for(i=1;i<n;i++)
	{
		temp=MAXVALUE;
		u=v;
		for(j=0;j<n;j++)
		{
			if((!s[j]) && (Dist[j]<temp))
			{
				u=j;
				temp=Dist[j];
			}
		}
		s[u]=true;
		for(j=0;j<n;j++)
		{
			if((!s[j]) && (Cost[u][j]<MAXVALUE))
			{
				newdist=Dist[u]+Cost[u][j];
				if(newdist<Dist[j])
				{
					Dist[j]=newdist;
					Prev[j]=u;
				}
			}
		}
	}
}
int main()
{
	int f,p,c,m,cow[100]={0},r=0;
	int i,j,k,t;
	scanf("%d%d%d%d",&f,&p,&c,&m);
	for (i=0;i<f;i++)
	{
		for (j=0;j<f;j++)
			Cost[i][j]=MAXVALUE;
		Cost[i][i]=0;
	}
	for (i=0;i<p;i++)
	{
		scanf("%d%d%d",&j,&k,&t);
		if (Cost[j-1][k-1]>t)
		{
			Cost[j-1][k-1]=t;
			Cost[k-1][j-1]=t;
		}
	}
	Dijkstra(f,0);
	for (i=1;i<=c;i++)
	{
		scanf("%d",&j);
		if (Dist[j-1]<=m)
			cow[r++]=i;
	}
	printf("%d\n",r);
	for (i=0;i<r;i++)
		printf("%d\n",cow[i]);
	return 0;
}
