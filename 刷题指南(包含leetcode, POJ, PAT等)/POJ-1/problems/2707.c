#include<stdio.h>
int main()
{
	int a,b,c,d,t;
	double e,f;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	while (a!=0 || b!=0 || c!=0 || d!=0)
	{
		if (a<b)
		{
			t=b;
			b=a;
			a=t;
		}
		if (c<d)
		{
			t=d;
			d=c;
			c=t;
		}
		e=100.0*c/a;
		f=100.0*d/b;
		if (e>f)
			e=f;
		t=(int)e;
		if (t>100)
			t=100;
		printf("%d%%\n",t);
		scanf("%d%d%d%d",&a,&b,&c,&d);
	}
	return 0;
}
