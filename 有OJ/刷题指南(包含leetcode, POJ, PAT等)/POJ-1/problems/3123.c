#include<stdio.h>
int n;
double pie[10000];
int piece(double area)
{
	int total=0,i;
	for (i=0;i<n;i++)
		total+=(int)(pie[i]/area);
	return total;
}
int main()
{
	int test,t,f,i;
	double high,low,mid;
	scanf("%d",&test);
	for (t=0;t<test;t++)
	{
		scanf("%d%d",&n,&f);
		f++;
		high=0;
		for (i=0;i<n;i++)
		{
			scanf("%lf",&pie[i]);
			pie[i]*=pie[i];
			if (pie[i]>high)
				high=pie[i];
		}
		low=0;
		while (high-low>0.00000001)
		{
			mid=(high+low)/2;
			if (piece(mid)<f)
				high=mid;
			else low=mid;
		}
		printf("%.4lf\n",low*3.14159265359);
	}
	return 0;
}
