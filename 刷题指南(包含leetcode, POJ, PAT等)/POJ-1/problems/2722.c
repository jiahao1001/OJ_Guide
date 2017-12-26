#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	double xa,ya,xb,yb,s,l,a;
	scanf("%d",&n);
	while (n!=0)
	{
		s=0;
		l=0;
		scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
		for (i=0;i<n;i++)
		{
			scanf("%lf",&a);
			l+=a;
			s+=a*a;
		}
		xa=xa/(xa+ya);
		ya=1-xa;
		xb=xb/(xb+yb);
		yb=1-xb;
		a=sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya));
		l=l*l/a/1.414213562373095;
		s/=2;
		printf("%.3lf\n",l-s);
		scanf("%d",&n);
	}
	return 0;
}
