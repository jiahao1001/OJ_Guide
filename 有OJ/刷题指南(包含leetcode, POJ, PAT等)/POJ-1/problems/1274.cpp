#include<iostream>
#define MN 400
bool check[MN];
bool hide[MN][MN]={false};
int match[MN],num,n,m;
bool DFS(int p);
int main()
{
	int save,i,j,k;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		num=n+m;
		for (i=0;i<n;i++)
		{
			scanf("%d",&save);
			for (j=0;j<save;j++)
			{
				scanf("%d",&k);
				hide[i][n+k-1]=true;
				hide[n+k-1][i]=true;
			}
		}
		memset(match,-1,sizeof(match));
		save=0;
		for(i=0;i<n;i++)
		{
			memset(check,false,sizeof(check));
			if (DFS(i))
				save++;
		}
		printf("%d\n",save);
		memset(hide,false,sizeof(hide));
	}
	return 0;
}
bool DFS(int p)
{
	int i,t,a,b;
	if (p<n)
		a=n,b=num;
	else a=0,b=n;
	for(i=a;i<b;i++)
	{
		if (hide[i][p] && !check[i])
		{
			check[i]=true;
			t=match[i];
			match[i]=p;
			if (t==-1 || DFS(t))
				return true;
			match[i]=t;
		}
	}
	return false;
}
