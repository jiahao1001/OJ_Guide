#include<stdio.h>
int n,m;
char t[100][100];
void dfs(int i,int j)
{
	t[i][j]='*';
	if (i>0)
	{
		if (j>0 && t[i-1][j-1]=='@')
			dfs(i-1,j-1);
		if (t[i-1][j]=='@')
			dfs(i-1,j);
		if (j+1<m && t[i-1][j+1]=='@')
			dfs(i-1,j+1);
	}
	if (j>0 && t[i][j-1]=='@')
		dfs(i,j-1);
	if (j+1<m && t[i][j+1]=='@')
		dfs(i,j+1);
	if (i+1<n)
	{
		if (j>0 && t[i+1][j-1]=='@')
			dfs(i+1,j-1);
		if (t[i+1][j]=='@')
			dfs(i+1,j);
		if (j+1<m && t[i+1][j+1]=='@')
			dfs(i+1,j+1);
	}
}
int main()
{
	int i,j,w;
	scanf("%d%d",&n,&m);
	while (n!=0 || m!=0)
	{
		w=0;
		for (i=0;i<n;i++)
			scanf("%s",t[i]);
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (t[i][j]=='@')
				{
					w++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",w);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
