#include<stdio.h>
int n;
int min,max,sum;
int main()
{
	int i,j;
	while (scanf("%d",&n),n!=0)
	{
		min=1001;
		max=-1;
		sum=0;
		for (i=0;i<n;i++)
		{
			scanf("%d",&j);
			sum+=j;
			if (j>max)
				max=j;
			if (j<min)
				min=j;
		}
		sum=sum-min-max;
		sum/=(n-2);
		printf("%d\n",sum);
	}
	return 0;
}
