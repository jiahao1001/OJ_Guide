#include<stdio.h>
#include<math.h>
int point(double r)
{
	if (r<=3)
		return 100;
	if (r<=6)
		return 80;
	if (r<=9)
		return 60;
	if (r<=12)
		return 40;
	if (r<=15)
		return 20;
	return 0;
}
int main()
{
	int p1,p2,i;
	double x,y,r;
	scanf("%lf%lf",&x,&y);
	while (x!=-100)
	{
		p1=0;
		p2=0;
		r=sqrt(x*x+y*y);
		p1+=point(r);
		for (i=0;i<2;i++)
		{
			scanf("%lf%lf",&x,&y);
			r=sqrt(x*x+y*y);
			p1+=point(r);
		}
		for (i=0;i<3;i++)
		{
			scanf("%lf%lf",&x,&y);
			r=sqrt(x*x+y*y);
			p2+=point(r);
		}
		printf("SCORE: %d to %d, ",p1,p2);
		if (p1==p2)
			printf("TIE.\n");
		else if (p1>p2)
			printf("PLAYER 1 WINS.\n");
		else printf("PLAYER 2 WINS.\n");
		scanf("%lf%lf",&x,&y);
	}
	return 0;
}
