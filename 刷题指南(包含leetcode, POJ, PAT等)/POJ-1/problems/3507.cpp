#include<stdio.h>
int main()
{
	int i;
	int max,min,sum;
	int s[6];
	while (1)
	{
		scanf("%d",&s[0]);
		max=min=sum=s[0];
		for (i=1;i<6;i++)
		{
			scanf("%d",&s[i]);
			sum+=s[i];
			if (s[i]>max)
				max=s[i];
			if (s[i]<min)
				min=s[i];
		}
		if (sum==0)
			break;
		printf("%g\n",((double)(sum-min-max))/4.0);
	}
	return 0;
}
