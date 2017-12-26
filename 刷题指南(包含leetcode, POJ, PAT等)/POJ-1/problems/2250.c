#include<stdio.h>
#include<string.h>
#define MAX 101
char words[MAX][30],wordt[MAX][30];
int c[MAX][MAX],m,n;
int LCS();
int main()
{
	int i,j,queue[MAX];
	while (scanf("%s",words[0])!=EOF)
	{
		m=1;
		scanf("%s",words[m]);
		while (strcmp(words[m],"#")!=0)
			scanf("%s",words[++m]);
		n=0;
		scanf("%s",wordt[n]);
		while (strcmp(wordt[n],"#")!=0)
			scanf("%s",wordt[++n]);
		i=LCS();
		j=i;
		while (c[m][n]!=0)
		{
			if (c[m][n]==c[m-1][n])
				m--;
			else if (c[m][n]==c[m][n-1])
				n--;
			else{
				m--;
				n--;
				queue[--i]=m;
			}
		}
		for (i=0;i<j;i++)
			printf("%s ",words[queue[i]]);
		printf("\n");
	}
	return 0;
}
int LCS()
{
	int i,j;
	memset(c,0,sizeof(c));
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (strcmp(words[i-1],wordt[j-1])==0)
				c[i][j]=c[i-1][j-1]+1;
			else c[i][j]=(c[i-1][j]>c[i][j-1]) ? c[i-1][j] : c[i][j-1];
		}
	}
	return c[m][n];
}
