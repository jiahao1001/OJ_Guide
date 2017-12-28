#include <stdio.h>
int main()
{
	int a,b,c,d,e,f,s;
	while (scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f),a!=0 || b!=0 || c!=0 || d!=0 || e!=0 || f!=0)
	{
		s=d+e+f;
		a-=11*e;
		b-=5*d;
		s+=c/4;
		c%=4;
		if (c!=0)
		{
			s++;
			if (c==3)
			{
				b--;
				a-=5;
			}
			else if (c==2)
			{
				b-=3;
				a-=6;
			}
			else if (c==1)
			{
				b-=5;
				a-=7;
			}
		}
		if (b>0)
		{
			s+=b/9;
			b%=9;
			if (b!=0)
			{
				s++;
				b-=9;
			}
		}
		a+=4*b;
		if (a>0)
		{
			s+=a/36;
			a%=36;
			if (a!=0)
				s++;
		}
		printf("%d\n",s);
	}
	return 0;
}
