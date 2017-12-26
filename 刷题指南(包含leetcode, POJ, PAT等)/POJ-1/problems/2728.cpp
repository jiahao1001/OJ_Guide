#include<stdio.h>
#include<math.h>
#define	Maxvalue 99999999
int n,x[1000],y[1000],h[1000];
double cost[1000][1000],dist[1000][1000];
double prim(double p);
int main()
{
	int i,j;
	double a,b;
	scanf("%d",&n);
	while (n!=0)
	{
		for (i=0;i<n;i++)
			scanf("%d%d%d",&x[i],&y[i],&h[i]);
		for (i=0;i<n;i++)
		{
			for (j=i+1;j<n;j++)
			{
				b=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				dist[i][j]=sqrt(b);
				dist[j][i]=dist[i][j];
				cost[i][j]=h[i]-h[j];
				if (cost[i][j]<0)
					cost[i][j]=-cost[i][j];
				cost[j][i]=cost[i][j];
			}
		}
		a=0;
		while (1)
		{
			b=prim(a);
			if (fabs(b-a)<0.0001)
				break;
			a=b;
		}
		printf("%.3lf\n",b);
		scanf("%d",&n);
	}
	return 0;
}
double prim(double p)
{
	int i,j,k,pre[1000]={0};
	bool tend[1000]={true};
	double mincost,lowcost[1000],v,totcost=0,totdist=0;
	lowcost[0]=0;
	for (j=1;j<n;j++)
		lowcost[j]=cost[j][0]-p*dist[j][0];
	for (i=1;i<n;i++)
	{
		mincost=Maxvalue;
		for (j=1;j<n;j++)
		{
			if (tend[j]==false && mincost>lowcost[j])
			{
				mincost=lowcost[j];
				k=j;
			}
		}
		tend[k]=true;
		totcost+=cost[pre[k]][k];
		totdist+=dist[pre[k]][k];
		for (j=0;j<n;j++)
		{
			if (tend[j]==false)
			{
				if ((v=cost[k][j]-p*dist[k][j])<lowcost[j])
				{
					lowcost[j]=v;
					pre[j]=k;
				}
			}
		}
	}
	return totcost/totdist;
}
