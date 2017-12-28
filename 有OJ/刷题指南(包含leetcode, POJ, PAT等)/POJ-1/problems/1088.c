#include<stdio.h>
int r,c,p[100][100],q[100][100]={0};
void dp(int i,int j)
{
	int x=-1;
	if (q[i][j]!=0)
		return ;
	if (i>0 && p[i-1][j]>p[i][j])
	{
		if (q[i-1][j]==0)
			dp(i-1,j);
		if (q[i-1][j]>x)
			x=q[i-1][j];
	}
	if (i<r-1 && p[i+1][j]>p[i][j])
	{
		if (q[i+1][j]==0)
			dp(i+1,j);
		if (q[i+1][j]>x)
			x=q[i+1][j];
	}
	if (j>0 && p[i][j-1]>p[i][j])
	{
		if (q[i][j-1]==0)
			dp(i,j-1);
		if (q[i][j-1]>x)
			x=q[i][j-1];
	}
	if (j<c-1 && p[i][j+1]>p[i][j])
	{
		if (q[i][j+1]==0)
			dp(i,j+1);
		if (q[i][j+1]>x)
			x=q[i][j+1];
	}
	q[i][j]=x+1;
}
int main()
{
	int i,j,m=0;
	scanf("%d%d",&r,&c);
	for (i=0;i<r;i++)
		for (j=0;j<c;j++)
			scanf("%d",&p[i][j]);
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			dp(i,j);
			if (q[i][j]>m)
				m=q[i][j];
		}
	}
	printf("%d\n",m+1);
	return 0;
}
