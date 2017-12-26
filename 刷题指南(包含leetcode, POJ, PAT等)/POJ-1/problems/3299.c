#include<stdio.h>
#include<math.h>
double d,t,h,e;
double Exp()
{
	double a=(d+273.16)*273.16;
	a=d/a;
	a=a*5417.7530;
	return exp(a);
}
void calH()
{
	double a;
	e=6.11*Exp();
	a=0.5555*(e-10.0);
	h=t+a;
}
void calT()
{
	double a;
	e=6.11*Exp();
	a=0.5555*(e-10.0);
	t=h-a;
}
void calD()
{
	double a=h-t;
	e=a/0.5555+10;
	e/=6.11;
	a=log(e);
	a/=5417.7530;
	a=1/273.16-a;
	a=1/a;
	d=a-273.16;
}
int main()
{
	double a;
	char str[100];
	int let[3];
	while (scanf("%s",str),str[0]!='E')
	{
		let[0]=let[1]=let[2]=0;
		scanf("%lf",&a);
		if (str[0]=='T')
			t=a,let[0]=1;
		else if (str[0]=='D')
			d=a,let[1]=1;
		else if (str[0]=='H')
			h=a,let[2]=1;
		scanf("%s%lf",str,&a);
		if (str[0]=='T')
			t=a,let[0]=1;
		else if (str[0]=='D')
			d=a,let[1]=1;
		else if (str[0]=='H')
			h=a,let[2]=1;
		if (let[0]==0)
			calT();
		else if (let[1]==0)
			calD();
		else calH();
		printf("T %.1lf D %.1lf H %.1lf\n",t,d,h);
	}
	return 0;
}
