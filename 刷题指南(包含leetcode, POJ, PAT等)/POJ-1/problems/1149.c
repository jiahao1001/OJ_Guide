#include<stdio.h>
void bfsnetworkflow();
int n,p[102][102]={0},r[102][102]={0};
int main()
{
	int m,i,j,k,q;
	short M[1001],f[1001]={0};
	scanf("%d%d",&m,&n);
	n++;
	for (i=1;i<=m;i++)
		scanf("%d",&M[i]);
	for (i=1;i<n;i++)
	{
		scanf("%d",&k);
		for (j=0;j<k;j++)
		{
			scanf("%d",&q);
			if (f[q]==0)
				p[0][i]+=M[q];
			else p[f[q]][i]=10000;
			f[q]=i;
		}
		scanf("%d",&p[i][n]);
	}
	bfsnetworkflow();
	return 0;
}
void bfsnetworkflow()
{
	int prev[102],minflow[102],queue[102];
	int i,j,v,pr,qs,qe,w;
	minflow[0]=10000;
	while(1)
	{
		for(i=0;i<102;i++)
			prev[i]=-2;
		prev[0]=-1;
		qs=0;
		qe=1;
		queue[qs]=0;
		while(qs<qe && prev[n]==-2)
		{
			v=queue[qs++];
			for(i=0;i<n+1;i++)
			{
				if(prev[i]==-2 && (pr=p[v][i]-r[v][i]))
				{
					prev[i]=v;
					queue[qe++]=i;
					minflow[i]=(minflow[v]<pr)?minflow[v]:pr;
				}
			} 
		} 
		if(prev[n]==-2)
			break;
		for(i=prev[n],j=n;i!=-1;j=i,i=prev[i])
		{
			r[i][j]+=minflow[n];
			r[j][i]=-r[i][j];
		}
	} 
	for(i=0,w=0;i<n;i++) 
		w=w+r[i][n];
	printf("%d\n",w);
}
