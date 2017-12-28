#include <stdio.h>
int main()
{
	int a[21][21][21]={0},i,j,k;
	for (i=0;i<21;i++)
	{
		for (j=0;j<21;j++)
		{
			a[0][i][j]=1;
			a[i][0][j]=1;
			a[i][j][0]=1;
		}
	}
	for (i=1;i<21;i++)
	{
		for (j=1;j<21;j++)
		{
			for (k=1;k<21;k++)
			{
				if (i<j && j<k)
					a[i][j][k]=a[i][j][k-1]+a[i][j-1][k-1]-a[i][j-1][k];
				else a[i][j][k]=a[i-1][j][k]+a[i-1][j-1][k]+a[i-1][j][k-1]-a[i-1][j-1][k-1];
			}
		}
	}
	scanf("%d %d %d",&i,&j,&k);
	while (i!=-1 || j!=-1 || k!=-1)
	{
		if (i<=0 || j<=0 || k<=0)
			printf("w(%d, %d, %d) = 1\n",i,j,k);
		else if (i>20 || j>20 || k>20)
			printf("w(%d, %d, %d) = %d\n",i,j,k,a[20][20][20]);
		else printf("w(%d, %d, %d) = %d\n",i,j,k,a[i][j][k]);
		scanf("%d %d %d",&i,&j,&k);
	}
	return 0;
}
