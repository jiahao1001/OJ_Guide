#include<stdio.h>
#include<string.h>
#define MAX 5001
char str[MAX],ing[MAX];
int n;
short c[MAX][MAX]={0};
int LCS();
int main()
{
	int i,j;
	scanf("%d",&n);
	scanf("%s",str);
	for (i=0,j=n-1;i<n;i++,j--)
		ing[j]=str[i];
	ing[n]='\0';
	printf("%d\n",n-LCS());
	return 0;
}
int LCS()
{
	int i,j;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (str[i-1]==ing[j-1])
				c[i][j]=c[i-1][j-1]+(short)1;
			else c[i][j]=(c[i-1][j]>c[i][j-1]) ? c[i-1][j] : c[i][j-1];
		}
	}
	return c[n][n];
}
