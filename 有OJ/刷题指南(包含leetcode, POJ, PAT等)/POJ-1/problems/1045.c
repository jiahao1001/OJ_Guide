#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	double vs,r,c,w,vr;
	scanf("%lf%lf%lf%d",&vs,&r,&c,&n);
	for (i=0;i<n;i++)
	{
		scanf("%lf",&w);
		vr=(r*c*w*vs)/sqrt(1+r*r*c*c*w*w);
		printf("%.3lf\n",vr);
	}
	return 0;
}
