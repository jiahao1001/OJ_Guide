#include<stdio.h>
#include<stdlib.h>
int size[500][1000],gift[1000],queue[500]={0},c,d,n,f;
char GE[500][500]={0};
int cmp(const void *a,const void *b);
void boxes(int p);
void dfs(int p,int q);
int main()
{
	int i,j;
	while (scanf("%d%d",&n,&d)!=EOF)
	{
		for (i=0;i<d;i++)
			scanf("%d",&gift[i]);
		qsort(gift,d,sizeof(gift[0]),cmp);
		for (i=0;i<n;i++)
		{
			for (j=0;j<d;j++)
				scanf("%d",&size[i][j]);
			qsort(size[i],d,sizeof(size[i][0]),cmp);
		}
		c=0;
		f=0;
		for (i=0;i<n;i++)
		{
			for (j=0;j<d;j++)
				if (gift[j]>=size[i][j])
					break;
			if (j==d)
			{
				queue[f++]=i;
				c=1;
			}
		}
		if (c==0)
			printf("Please look for another gift shop!\n");
		else{
			for (i=0;i<f;i++)
				boxes(i);
			for (i=0;i<f;i++)
				dfs(i,1);
			printf("%d\n",c);
			for (i=0;i<f;i++)
				for (j=0;j<f;j++)
					GE[i][j]=0;
		}
	}
	return 0;
}
int cmp(const void *a,const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if (x<y)
		return 1;
	else if (x>y)
		return -1;
	else return 0;
}
void boxes(int p)
{
	int i,j,q=queue[p];
	for (i=0;i<f;i++)
	{
		for (j=0;j<d;j++)
			if (size[q][j]<=size[queue[i]][j])
				break;
		if (j==d)
			GE[p][i]=1,GE[i][p]=-1;;
	}
}
void dfs(int p,int q)
{
	int i,j;
	for (i=0;i<f;i++)
	{
		if (GE[p][i]==1)
		{
			for (j=0;j<f;j++)
			{
				if (GE[j][p]==1 && GE[i][j]==-1)
					GE[i][j]=0,GE[j][i]=0;
			}
			dfs(i,q+1);
		}
	}
	if (q>c)
		c=q;
}
