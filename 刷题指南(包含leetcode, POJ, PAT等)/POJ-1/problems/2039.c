#include <stdio.h>
int main()
{
    int n,i,j,k;
	char s[100][20];
	scanf("%d",&n);
	while (n!=0)
	{
		getchar();
		i=0;
		j=0;
		k=1;
		while ((s[i][j]=getchar())!='\n')
		{
			j+=k;
			if (j==n || j==-1)
			{
				k=0-k;
				j+=k;
				i++;
			}
		}
		for (j=0;j<n;j++)
			for (k=0;k<i;k++)
				printf("%c",s[k][j]);
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
