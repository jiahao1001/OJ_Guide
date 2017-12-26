#include<stdio.h>
int main()
{
	int n,i;
	double c,a,b,d=0;
	scanf("%d%lf%lf",&n,&a,&b);
	for (i=0;i<n;i++)
	{
		scanf("%lf",&c);
		d+=(n-i)*c;
	}
	d=b-a-2*d;
	d=a+d/(n+1);
	printf("%.2lf\n",d);
	return 0;
}
