#include<stdio.h>
#include<math.h>
int main()
{
	double x,y,z,i,j,c,a,b,m;
	while (scanf("%lf%lf%lf",&x,&y,&c)!=EOF)
	{
		i=0;
		j=(x>y) ? y:x;
		while (0.00001<j-i)
		{
			z=(i+j)/2;
			a=sqrt((x+z)*(x-z));
			b=sqrt((y+z)*(y-z));
			m=a*b/(a+b)-c;
			if (m<0.0001 && m>-0.0001)
				break;
			else if (m<-0.0001)
				j=z-0.000001;
			else i=z+0.000001;
		}
		printf("%.3lf\n",(i+j)/2);
	}
	return 0;
}
