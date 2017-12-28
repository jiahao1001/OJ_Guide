#include <stdio.h>
int main()
{
	int a[16],i,j,k,l,m;
	scanf("%d",&a[0]);
	while (a[0]!=-1)
	{
		i=0;
		m=0;
		while (a[i]!=0)
			scanf("%d",&a[++i]);
		for (j=0;j<i;j++)
		{
			l=a[j]*2;
			for (k=0;k<i;k++)
			{
				if (a[k]==l)
				{
					m++;
					break;
				}
			}
		}
		printf("%d\n",m);
		scanf("%d",&a[0]);
	}
	return 0;
}
