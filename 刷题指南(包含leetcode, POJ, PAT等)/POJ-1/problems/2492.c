#include<stdio.h>
int p[2001],s[2001];
int root(int i);
void  merge(int i,int j);
int main()
{
	int n,m,c,i,j,k=0,a,b,x,y,z;
	scanf("%d",&x);
	for (i=0;i<x;i++)
	{
		scanf("%d%d",&n,&m);
		k++;
		c=0;
		for (j=n;j>0;j--)
		{
			p[j]=-1;
			s[j]=0;
		}
		for (j=0;j<m;j++)
		{
			scanf("%d%d",&a,&b);
			if (c==0)
			{
				y=root(a);
				z=root(b);
				if (y==z)
					c=1;
				if (s[a]!=0)
					merge(s[a],z);
				else s[a]=b;
				if (s[b]!=0)
					merge(y,s[b]);
				else s[b]=a;
			}
		}
		printf("Scenario #%d:\n",k);
		if (c==0)
			printf("No suspicious bugs found!\n\n");
		else printf("Suspicious bugs found!\n\n");
	}
	return 0;
}
int root(int i)
{
	int r,s;
	for (r=i;p[r]>0;r=p[r]);
	while (i!=r)
	{
		s=i;
		i=p[i];
		p[s]=r;
	}	
	return r;
}
void  merge(int i,int j)
{
	i=root(i);
	j=root(j);
	if (i==j)
		return ;
	if (p[i]<p[j])
	{
		p[i]+=p[j];
		p[j]=i;
	}
	else 
	{
		p[j]+=p[i];
		p[i]=j;
	}
}
