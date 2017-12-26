#include<stdio.h>
#define MAXNUM 99999
struct edge{
	int st,ed,val;
}f[10001];
int d[10001],max=0,min=10000,n;
int bellman_ford(int s);
int main()
{
	int i;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d",&f[i].st,&f[i].ed);
		f[i].ed++;
		f[i].val=2;
		if (f[i].st<min)
			min=f[i].st;
		if (f[i].ed>max)
			max=f[i].ed;
	}
	printf("%d\n",bellman_ford(min));
	return 0;
}
int bellman_ford(int s)
{
	int i,j,c;
	for (i=min;i<=max;i++)
		d[i]=-MAXNUM;
	d[s]=0;
	for (i=min;i<=max;i++)
	{
		c=0;
		for (j=0;j<n;j++)
		{
			if (d[f[j].st]==-MAXNUM)
				continue;
			if (d[f[j].ed]<d[f[j].st]+f[j].val)
			{
				c=1;
				d[f[j].ed]=d[f[j].st]+f[j].val;
			}
		}
		for(j=min;j<max;j++)
			if(d[j]!=-MAXNUM && d[j]>d[j+1])
			{
				d[j+1]=d[j];
				c=1;
			}
		for(j=max;j>min;j--)
			if(d[j]!=-MAXNUM && d[j]-1>d[j-1])
			{
				d[j-1]=d[j]-1;
				c=1;
			}
		if (c==0)
			break;
	}
	return d[max];
}
