#include<stdio.h>
int Parent[1002],x[1002],y[1002];
bool flag[1002];
int root(int i);
void  merge(int i,int j);
int main()
{
	int i,j,k,d,n;
	char s[10];
	scanf("%d%d",&n,&d);
	for (i=1;i<=n;i++)
	{
		Parent[i]=-1;
		flag[i]=false;
		scanf("%d%d",&x[i],&y[i]);	
	}
	while (scanf("%s",s)!=EOF)
	{
		if (s[0]=='O')
		{
			scanf("%d",&k);
			flag[k]=true;
			for (i=1;i<=n;i++)
			{
				if (flag[i]==true && ((x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k]))<=d*d)
					merge(i,k);
			}
		}
		else{
			scanf("%d%d",&j,&k);
			if (root(j)==root(k))
				printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;
}
int root(int i)
{
	int r,p;
	for (r=i;Parent[r]>0;r=Parent[r]);
	while (i!=r)
	{
		p=i;
		i=Parent[i];
		Parent[p]=r;
	}	
	return r;
}
void  merge(int i,int j)
{
	i=root(i);
	j=root(j);
	if (i==j)
		return ;
	if (Parent[i]<Parent[j])
	{
		Parent[i]+=Parent[j];
		Parent[j]=i;
	}
	else 
	{
		Parent[j]+=Parent[i];
		Parent[i]=j;
	}
}
