#include<stdio.h>
#define MAX xxx//图的最大顶点数
#define MAXVALUE 999999999//无穷大的权,即为不连通
int GE[MAX][MAX];
int Prim(int n);
int main()
{
	int n,i,j,k,q;
	scanf("%d",&n);
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			scanf("%d",&GE[i][j]);
	scanf("%d",&q);
	for (i=0;i<q;i++)
	{
		scanf("%d%d",&j,&k);
		j--;
		k--;
		GE[j][k]=0;
		GE[k][j]=0;
	}
	printf("%d\n",Prim(n));
	return 0;
}
int Prim(int n)//Prim算法适合边数较多的网的最小生成树,n为结点数
{
	int i,j,k,min=0,mincost;
	int tend[MAX]={1},lowcost[MAX]={-1};
	for (j=1;j<n;j++)
		lowcost[j]=GE[0][j];
	for (i=1;i<n;i++)
	{
		mincost=MAXVALUE;
		for (j=1;j<n;j++)
		{
			if (lowcost[j]>=0 && mincost>lowcost[j])
			{
				mincost=lowcost[j];
				k=j;
			}
		}
		lowcost[k]=-1;//已经使用过该点
		//tend[k],k是这条新增边的两个端点
		min+=mincost;
		for (j=0;j<n;j++)
		{
			if (GE[k][j]<lowcost[j])
			{
				lowcost[j]=GE[k][j];
				tend[j]=k;
			}
		}
	}
	return min;//min是最小生成树的总权值
}
