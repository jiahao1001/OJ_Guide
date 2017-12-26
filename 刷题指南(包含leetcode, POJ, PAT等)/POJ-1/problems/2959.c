#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,m;
	double D,d,s;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%lf%lf%lf",&D,&d,&s);
		D=3.1415926/asin((s+d)/(D-d));
		printf("%d\n",(int)D);
	}
	return 0;
}
