#include<stdio.h>
int n,m;
char t[100][100],p[100][100]={0};
void dfs(int i,int j)
{
	if (p[i][j]==1)
		return;
	p[i][j]=1;
	if (i>0)
	{
		if (j>0 && t[i-1][j-1]=='W')
			dfs(i-1,j-1);
		if (t[i-1][j]=='W')
			dfs(i-1,j);
		if (j+1<m && t[i-1][j+1]=='W')
			dfs(i-1,j+1);
	}
	if (j>0 && t[i][j-1]=='W')
		dfs(i,j-1);
	if (j+1<m && t[i][j+1]=='W')
		dfs(i,j+1);
	if (i+1<n)
	{
		if (j>0 && t[i+1][j-1]=='W')
			dfs(i+1,j-1);
		if (t[i+1][j]=='W')
			dfs(i+1,j);
		if (j+1<m && t[i+1][j+1]=='W')
			dfs(i+1,j+1);
	}
}
int main()
{
	int i,j,w=0;
	scanf("%d%d",&n,&m);
	for (i=0;i<n;i++)
		scanf("%s",t[i]);
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (t[i][j]=='W' && p[i][j]==0)
			{
				w++;
				dfs(i,j);
			}
		}
	}
	printf("%d\n",w);
	return 0;
}
