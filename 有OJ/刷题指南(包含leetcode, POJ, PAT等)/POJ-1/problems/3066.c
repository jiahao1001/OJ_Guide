#include<stdio.h>
double A,B,re,su,lt,r,s;
int main()
{
	int m,p,a,b,x,y,i;
	while (scanf("%d%d%d%d",&m,&p,&a,&b)!=EOF)
	{
		p/=2;
		x=(m-b)*a/(1+a);
		x-=x%a;
		y=b+x/a;
		i=m-x-y-1;
		A=(double)i*i/a;
		B=A;
		x=m-y-1;
		r=1.0/a;
		re=r;
		su=(double)a;
		s=su;
		for (i=1;i<p;i++)
		{
			re*=r;
			su*=s;
			B*=A;
		}
		lt=(double)x*re+(double)y*su+B;
		printf("%.0lf\n",lt);
	}	
	return 0;
}
