#include<stdio.h>
#include<string.h>
#define MAX 400
bool Check[MAX];
bool Hide[MAX][MAX]={false};//图的邻接矩阵表示
int Match[MAX],N,P;
bool DFS(int p);
int main()
{
	int n,i,j,k,s,Save,pi;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d",&P,&N);
		memset(Hide,false,sizeof(Hide));
		for (j=0;j<P;j++)
		{
			scanf("%d",&s);
			for (k=0;k<s;k++)
			{
				scanf("%d",&pi);
				Hide[j][pi-1+P]=true;
				Hide[pi-1+P][j]=true;
			}
		}
		Save=0;
		memset(Match,-1,sizeof(Match));	
		for(pi=0;pi<P;pi++)
		{
			memset(Check,false,sizeof(Check));
			if (DFS(pi))
				Save++;
		}
		if (Save==P)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
bool DFS(int p)
{
	int i,t;
	int a,b;
	if (p>=P)
		a=0,b=P;
	else a=P,b=N+P;
	for(i=a;i<b;i++)
	{
		if (Hide[i][p] && !Check[i])
		{
			Check[i]=true;
			t=Match[i];
			Match[i]=p;
			if (t==-1 || DFS(t))
				return true;
			Match[i]=t;
		}
	}
	return false;
}
