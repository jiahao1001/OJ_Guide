#include<stdio.h>
int main()
{
	int test,t,i,j,n;
	int max,min;
	scanf("%d",&test);
	for (t=0;t<test;t++)
	{
		scanf("%d",&n);
		max=-1;
		min=100;
		for (i=0;i<n;i++)
		{
			scanf("%d",&j);
			if (j>max)
				max=j;
			if (j<min)
				min=j;
		}
		printf("%d\n",2*(max-min));
	}
	return 0;
}
