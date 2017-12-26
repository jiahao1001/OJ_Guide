#include <stdio.h>
int main()
{
	int n,i,j,x,y,p[11][11]={0};
	for (i=0;i<11;i++)
	{
		p[0][i]=1;
		p[i][0]=1;
		p[1][i]=1;
		p[i][1]=1;
	}
	for (i=2;i<11;i++)
	{
		for (j=2;j<11;j++)
		{
			if (j>i)
				p[i][j]=p[i][i];
			else p[i][j]=p[i][j-1]+p[i-j][j];
		}
	}
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",p[x][y]);
	}
	return 0;
}
