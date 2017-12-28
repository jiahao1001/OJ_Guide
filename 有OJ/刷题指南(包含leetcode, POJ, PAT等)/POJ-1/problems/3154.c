#include <stdio.h>
int n,m;
double x,y;
int main()
{
	int i;
	double s=0,p;
	scanf("%d%d",&n,&m);
	m+=n;
	x=(double)10000/n;
	y=(double)10000/m;
	for (i=1;i<n;i++)
	{
		p=(x*i)/y;
		p-=(int)p;
		if ((int)(p*2)==1)
			s+=1-p;
		else s+=p;
	}
	printf("%.4lf\n",s*y);
	return 0;
}
