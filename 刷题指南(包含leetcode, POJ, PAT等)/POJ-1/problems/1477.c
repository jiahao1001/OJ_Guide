#include<stdio.h>
int n,s[50];
int main()
{
	int i,j,k,t=0;
	while (scanf("%d",&n),n!=-0)
	{
		for (i=0,j=0;i<n;i++)
		{
			scanf("%d",&s[i]);
			j+=s[i];
		}
		j/=n;
		for (i=0,k=0;i<n;i++)
		{
			if (s[i]>j)
				k+=s[i]-j;
		}
		printf("Set #%d\n",++t);
		printf("The minimum number of moves is %d.\n\n",k);
	}
	return 0;
}
