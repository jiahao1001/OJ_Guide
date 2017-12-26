#include <stdio.h>
int main()
{
	int m,n,i,j,k,num[100]={0};
	char st[100][51];
	scanf("%d %d\n",&n,&m);
	for (i=0;i<m;i++)
	{
		scanf("%s",st[i]);
		for (j=0;j<n;j++)
		{
			for (k=j+1;k<n;k++)
			{
				if (st[i][j]>st[i][k])
					num[i]++;
			}
		}
	}
	for (i=0;i<m;i++)
	{
		k=0;
		for (j=0;j<m;j++)
		{
			if (num[k]>num[j])
				k=j;
		}
		printf("%s\n",st[k]);
		num[k]=10000000;
	}
	return 0;
}
