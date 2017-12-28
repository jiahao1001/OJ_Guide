#include <stdio.h>
int w,h,num,max;
char farm[1000][80];
void dfs(int i,int j)
{
	num++;
	farm[i][j]='.';
	if (i>0 && farm[i-1][j]=='*')
		dfs(i-1,j);
	if (i<h-1 && farm[i+1][j]=='*')
		dfs(i+1,j);
	if (j>0 && farm[i][j-1]=='*')
		dfs(i,j-1);
	if (j<w-1 && farm[i][j+1]=='*')
		dfs(i,j+1);
}
int main()
{
	int i,j;
	scanf("%d%d",&w,&h);
	for (i=0;i<h;i++)
		scanf("%s",farm[i]);
	max=0;
	for (i=0;i<h;i++)
	{
		for (j=0;j<w;j++)
		{
			if (farm[i][j]=='*')
			{
				num=0;
				dfs(i,j);
				if (num>max)
					max=num;
			}
		}
	}
	printf("%d\n",max);
	return 0;
}
