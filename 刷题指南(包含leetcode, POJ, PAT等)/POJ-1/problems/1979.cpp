#include<stdio.h>
#include<string.h>
int w,h,count;
char t[30][30];
bool p[30][30]={false};
void dfs(int i,int j)
{
	if (p[i][j]==true)
		return;
	p[i][j]=true;
	count++;
	if (i>0 && t[i-1][j]=='.')
		dfs(i-1,j);
	if (j>0 && t[i][j-1]=='.')
		dfs(i,j-1);
	if (j+1<w && t[i][j+1]=='.')
		dfs(i,j+1);
	if (i+1<h && t[i+1][j]=='.')
		dfs(i+1,j);
}
int main()
{
	int i,j;
	while (scanf("%d%d",&w,&h),w!=0 || h!=0)
	{
		count=0;
		memset(p,false,sizeof(p));
		for (i=0;i<h;i++)
			scanf("%s",t[i]);
		for (i=0;i<h;i++)
			for (j=0;j<w;j++)
				if (t[i][j]=='@')
				{
					dfs(i,j);
					break;
				}
		printf("%d\n",count);
	}
	return 0;
}
