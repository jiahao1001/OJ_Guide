#include<stdio.h>
int main()
{
	int p,q,r,s,i;
	double d;
	while (scanf("%d%d%d%d",&p,&q,&r,&s)!=EOF)
	{
		if (q>p-q)
			q=p-q;
		if (s>r-s)
			s=r-s;
		d=1.0;
		p++;
		r++;
		for (i=1;i<=q && i<=s;i++)
			d*=1.0*(p-i)/(r-i);
		while (i<=q)
		{
			d*=1.0*(p-i)/i;
			i++;
		}
		while (i<=s)
		{
			d*=1.0*i/(r-i);
			i++;
		}
		printf("%.5lf\n",d);
	}
	return 0;
}
