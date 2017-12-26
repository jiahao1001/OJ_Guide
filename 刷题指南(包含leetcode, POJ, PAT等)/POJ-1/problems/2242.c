#include<stdio.h>
#include<math.h>
#define pi 3.141592653589793
int main()
{
	double a,b,c,xa,ya,xb,yb,xc,yc,s;
	while (scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc)!=EOF)
	{
		a=sqrt((xc-xb)*(xc-xb)+(yc-yb)*(yc-yb));
		b=sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc));
		c=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
		xa=(a+b+c)/2;
		s=sqrt(xa*(xa-a)*(xa-b)*(xa-c));
		s=a*b*c/s/2*pi;
		printf("%.2lf\n",s);
	}
	return 0;
}
