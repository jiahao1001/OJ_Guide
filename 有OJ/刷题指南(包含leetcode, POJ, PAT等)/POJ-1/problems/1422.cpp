#include<stdio.h>
#include<string.h>
#define MAX 120
bool Check[MAX];
bool Hide[MAX][MAX]={false};
int Match[MAX],n;
bool DFS(int p);
int main()
{
	int t,i,j,a,b,m,Save;
	scanf("%d",&t);
	for (j=0;j<t;j++)
	{
		scanf("%d%d",&n,&m);
		memset(Hide,false,sizeof(Hide));
		for (i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			Hide[a-1][b-1]=true;
		}
		Save=0;
		memset(Match,-1,sizeof(Match));
		for(i=0;i<n;i++)
		{
			memset(Check,false,sizeof(Check));
			if (DFS(i))
				Save++;
		}
		printf("%d\n",n-Save);
	}
	return 0;
}
bool DFS(int p)
{
	int i,t;
	for(i=0;i<n;i++)
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
