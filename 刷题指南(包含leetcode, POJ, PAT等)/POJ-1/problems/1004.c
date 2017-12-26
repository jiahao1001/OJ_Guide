#include <stdio.h>
int main()
{
	double sum=0.0,t;
	int i=1;
	for (;i<=12;i++)
	{
		scanf("%lf",&t);
		sum+=t;
	}
	sum/=12.0;
	printf("$%.2lf\n",sum);
	return 0;
}
