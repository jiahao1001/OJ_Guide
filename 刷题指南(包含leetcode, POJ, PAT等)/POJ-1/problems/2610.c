#include<stdio.h>
double gx,gy,dx,dy,x,y;
double dist(double x,double y,double hx,double hy)
{
	return (x-hx)*(x-hx)+(y-hy)*(y-hy);
}
int main()
{
	int flag=0;
	double cx,cy;
	scanf("%lf%lf%lf%lf",&gx,&gy,&dx,&dy);
	while (scanf("%lf%lf",&x,&y)!=EOF)
	{
		if (flag==0)
		{
			cx=dist(x,y,gx,gy)*4;
			cy=dist(x,y,dx,dy);
			if (cx<cy+0.0000001)
			{
				flag=1;
				cx=x;
				cy=y;
			}
		}
	}
	if (flag==0)
		printf("The gopher cannot escape.\n");
	else printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",cx,cy);
	return 0;
}
