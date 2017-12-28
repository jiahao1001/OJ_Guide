#include <stdio.h>
#define MAX 25
int flag1[MAX][MAX]={0},n;
int flag2[MAX][MAX]={0};
void sign (int a, int b)
{
	flag1[a-1][b-1]+=flag2[a][b];
	flag1[a-1][b]+=flag2[a][b];
	flag1[a][b-1]+=flag2[a][b];
	flag1[a][b+1]+=flag2[a][b];
	flag1[a+1][b]+=flag2[a][b];
	flag1[a+1][b+1]+=flag2[a][b];
}
void copy ()
{
	int i,j;
	for (i=0;i<MAX;i++)
		for (j=0;j<MAX;j++)
			flag2[i][j]=flag1[i][j];
}
void search ()
{
	int i,j;
	for (i=0;i<MAX;i++)
		for (j=0;j<MAX;j++)
			if (flag2[i][j]!=0)
                sign(i,j);
	copy();
	memset(flag1,0,sizeof(flag1));
}
void solve ()
{
	int i;
	flag2[n][n]=1;
	sign(n,n);
	copy();
	memset(flag1,0,sizeof(flag1));
	for (i=2;i<=n;i++)
		search();
	printf("%d\n",flag2[n][n]);
}
int main ()
{
	int i,t;
	scanf("%d",&t);
    for (i=0;i<t;i++)
	{
		scanf("%d",&n);
		solve();
	}
	return 0;
}
