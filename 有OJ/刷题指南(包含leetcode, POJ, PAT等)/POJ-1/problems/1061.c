#include<stdio.h>
__int64 x,y;
__int64 ext_euclid(__int64 a,__int64 b)
{
	__int64 t,d;
	if (b==0)
	{
		x=1;
		y=0;
		return a;
	}
	d=ext_euclid(b,a%b);
	t=x;
	x=y;
	y=t-a/b*y;
	return d;
}
__int64 mod(__int64 a,__int64 b,__int64 n)
{
	__int64 d,e;
	d=ext_euclid(a,n);
	if(b%d>0)
		return -1;
	else
	{
		e=(x*(b/d))%n;
		if(e<0)
			e=e+n;
		e=e%(n/d);
		return e;
	}
}

int main()
{
    __int64 x1,y1,m,n,l,e,b;
    scanf("%I64d%I64d%I64d%I64d%I64d",&x1,&y1,&m,&n,&l);
	m=(l+m-n)%l;
	b=(l+y1-x1)%l;
	e=mod(m,b,l);
	if (e==-1)
		printf("Impossible\n");
	else printf("%I64d\n",e);
	return 0;
}
