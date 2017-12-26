#include<stdio.h>
#include<math.h>
#define MAXS 500
#define MAXT 50
int star,telescope;
double sx[MAXS],sy[MAXS],sz[MAXS];
double tx[MAXT],ty[MAXT],tz[MAXT],r[MAXT];
double dist(double x1,double y1,double z1,double x2,double y2,double z2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}
bool seen(int p)
{
	int i;
	double a,b,c,sita;
	b=dist(sx[p],sy[p],sz[p],0,0,0);
	for (i=0;i<telescope;i++)
	{
		a=dist(sx[p],sy[p],sz[p],tx[i],ty[i],tz[i]);
		c=dist(tx[i],ty[i],tz[i],0,0,0);
		sita=acos((b*b+c*c-a*a)/(2*b*c));
		if (sita<r[i])
			return true;
	}
	return false;
}
int main()
{
	int i,sum;
	scanf("%d",&star);
	while (star!=0)
	{
		for (i=0;i<star;i++)
			scanf("%lf%lf%lf",&sx[i],&sy[i],&sz[i]);
		scanf("%d",&telescope);
		for (i=0;i<telescope;i++)
			scanf("%lf%lf%lf%lf",&tx[i],&ty[i],&tz[i],&r[i]);
		sum=0;
		for (i=0;i<star;i++)
			if (seen(i)==true)
				sum++;
		printf("%d\n",sum);
		scanf("%d",&star);
	}
	return 0;
}
