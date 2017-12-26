#include<stdio.h>
#include<math.h>
int main()
{
	double D,d,v;
	while(scanf("%lf%lf",&D,&v)&&(D||v))
	{
		d=pow((D*D*D-(6*v/3.1415926535)),1.0000000/3);
		printf("%.3lf\n",d);
	}
	return 0;
}
