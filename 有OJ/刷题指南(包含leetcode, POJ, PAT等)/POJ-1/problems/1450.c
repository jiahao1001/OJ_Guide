#include<stdio.h>
int main()
{
	int total;
	int m,n,i;
	scanf("%d",&total);
	for(i=1;i<=total;i++)
	{
		scanf("%d%d",&m,&n);
		printf("Scenario #%d:\n",i);
		m=m*n;
		if (m%2==0)
			printf("%d.00\n",m);
		else
			printf("%d.41\n",m);
		printf("\n");
	}
	return 0;
}
