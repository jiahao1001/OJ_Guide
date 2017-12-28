#include<stdio.h>
#include<math.h>
int main()
{
    double x1,y1,a,x2,y2,b,c,s,A,B,area;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&a,&x2,&y2,&b)!=EOF)
	{
		if(a<b)
			c=a,a=b,b=c;
		c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		if(c>=a+b)
			printf("0.000\n");
		else if (c<=a-b)
			printf("%.3lf\n",3.1415926*b*b);
		else{
			A=acos((b*b+c*c-a*a)/2/b/c);
			B=acos((a*a+c*c-b*b)/2/a/c);
			s=(a+b+c)/2;
			s=sqrt(s*(s-a)*(s-b)*(s-c));
			area=a*a*B+b*b*A-2*s;
			printf("%.3lf\n",area);
		}
	}
	return 0;
}
