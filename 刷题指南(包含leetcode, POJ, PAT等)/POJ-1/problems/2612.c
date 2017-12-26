#include<stdio.h>
int n;
char f[12][12]={0};
void add(int x,int y)
{
	f[x-1][y-1]++;
	f[x-1][y]++;
	f[x-1][y+1]++;
	f[x][y-1]++;
	f[x][y+1]++;
	f[x+1][y-1]++;
	f[x+1][y]++;
	f[x+1][y+1]++;
	f[x][y]=9;
}
int main()
{
	int i,j,k=0;
	char c[11][11]={0};
	scanf("%d\n",&n);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
			if (getchar()=='*')
				add(i,j);
		getchar();
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
			if (getchar()=='x')
			{
				c[i][j]=1;
				if (f[i][j]>8)
					k=1;
			}
		getchar();
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (f[i][j]>8 && k==1)
				putchar('*');
			else if (c[i][j]==1)
				putchar(f[i][j]+'0');
			else putchar('.');
		}
		putchar('\n');
	}
	return 0;
}
