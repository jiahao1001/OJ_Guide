#include<stdio.h>
int x,y,z,n;
int main()
{
	int i;
	double p;
	scanf("%d%d%d%d",&x,&y,&z,&n);
	p=(double)x/n;
	for (i=0;i<n;i++)
		printf("%.8lf 0 0 %.8lf %d %d\n",i*p,(i+1)*p,y,z);
	return 0;
}
