#include<stdio.h>
int board[20][20],w,h,step;
void dfs(int i,int j,int n)
{
	int a,b;
	if (n>step)
		return;
	if (i>0 && board[i-1][j]!=1)
	{
		for (a=i-1;a>=0;a--)
		{
			if (board[a][j]==3)
			{
				if (n<step)
					step=n;
				return;
			}
			if (board[a][j]==1)
			{
				board[a][j]=0;
				dfs(a+1,j,n+1);
				board[a][j]=1;
				break;
			}
		}
	}
	if (j>0 && board[i][j-1]!=1)
	{
		for (a=j-1;a>=0;a--)
		{
			if (board[i][a]==3)
			{
				if (n<step)
					step=n;
				return;
			}
			if (board[i][a]==1)
			{
				board[i][a]=0;
				dfs(i,a+1,n+1);
				board[i][a]=1;
				break;
			}
		}
	}
	if (i+1<h && board[i+1][j]!=1)
	{
		for (a=i+1;a<h;a++)
		{
			if (board[a][j]==3)
			{
				if (n<step)
					step=n;
				return;
			}
			if (board[a][j]==1)
			{
				board[a][j]=0;
				dfs(a-1,j,n+1);
				board[a][j]=1;
				break;
			}
		}
	}
	if (j+1<w && board[i][j+1]!=1)
	{
		for (a=j+1;a<w;a++)
		{
			if (board[i][a]==3)
			{
				if (n<step)
					step=n;
				return;
			}
			if (board[i][a]==1)
			{
				board[i][a]=0;
				dfs(i,a-1,n+1);
				board[i][a]=1;
				break;
			}
		}
	}
}
int main()
{
	int i,j,x,y;
	scanf("%d%d",&w,&h);
	while (w!=0 || h!=0)
	{
		for (i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				scanf("%d",&board[i][j]);
				if (board[i][j]==2)
				{
					x=i;
					y=j;
				}
			}
		}
		step=11;
		dfs(x,y,1);
		if (step>10)
			printf("-1\n");
		else printf("%d\n",step);
		scanf("%d%d",&w,&h);
	}
	return 0;
}
