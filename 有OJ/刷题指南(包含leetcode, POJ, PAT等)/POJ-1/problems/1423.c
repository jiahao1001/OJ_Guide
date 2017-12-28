#include<stdio.h>
#include<math.h>
const double e=2.7182818284590452354,pi=3.141592653589793239;
int main()
{
	int n,i,d;
	double a;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&d);
		if (d<4)
			a=1;
		else a=log10(sqrt(2*pi*d))+d*log10(d/e)+1;
		printf("%d\n",(int)a);
	}
	return 0;
}
