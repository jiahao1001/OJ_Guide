#include<stdio.h>
#include<string.h>
#define MAX 201
char s[MAX],t[MAX];
int c[MAX][MAX];
int LCS(int m,int n);
int main()
{
	while (scanf("%s",s)!=EOF)
	{
		scanf("%s",t);
		printf("%d\n",LCS(strlen(s),strlen(t)));
	}
	return 0;
}
int LCS(int m,int n)
{
	int i,j;
	memset(c,0,sizeof(c));
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (s[i-1]==t[j-1])
				c[i][j]=c[i-1][j-1]+1;
			else c[i][j]=(c[i-1][j]>c[i][j-1]) ? c[i-1][j] : c[i][j-1];
		}
	}
	return c[m][n];
}
