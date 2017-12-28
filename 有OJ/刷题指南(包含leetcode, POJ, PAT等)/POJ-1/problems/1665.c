#include<stdio.h>
#define pi 3.1415927
int main()
{
	int a,i=0;
	double x,b,e,f;
	scanf("%lf%d%lf",&x,&a,&b);
	while (a!=0 && b!=0)
	{
		i++;
		e=pi*x*a/(12*5280);
		f=3600*e/b;
		printf("Trip #%d: %.2lf %.2lf\n",i,e,f);
	    scanf("%lf%d%lf",&x,&a,&b);
	}
	return 0;
}
