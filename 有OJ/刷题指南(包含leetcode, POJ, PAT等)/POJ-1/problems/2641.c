#include<stdio.h>
#include<math.h>
int main ()
{
	int a,b,s,m,n;
	double y,x,angle,velocity;
	scanf("%d%d%d%d%d",&a,&b,&s,&m,&n);
	while (a!=0 || b!=0 || s!=0 || m!=0 || n!=0)
	{
		x=(double)a*m;
		y=(double)b*n;
		angle=atan(y/x)*180/3.14159265358;
		velocity=sqrt(x*x+y*y)/s;
		printf("%.2lf %.2lf\n",angle,velocity);
		scanf("%d%d%d%d%d",&a,&b,&s,&m,&n);
	}
	return 0;
}
