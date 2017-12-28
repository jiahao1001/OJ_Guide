#include <stdio.h>
#define pi 3.14159265358979323846
int main()
{
	int n,i;
	int m;
	double a,b;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%lf %lf",&a,&b);
		m=(int)((a*a+b*b)*pi/100)+1;
		printf("Property %d: This property will begin eroding in year %d.\n",i,m);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
