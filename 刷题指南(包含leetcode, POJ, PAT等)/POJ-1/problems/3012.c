#include<stdio.h>
int main()
{
	__int64 n,k,sm;
	__int64 m,o,base,ans,p;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d%I64d",&n,&k,&sm);
		m=sm;
		o=1;
		ans=1;
		p=k;
		for(base=10;p;p/=2,base=(base*base)%m)
			if (p&1) 
				o=(o*base)%m;
		o=(o+1)%m;
		p=n;
		for(base=o;p;p/=2,base=(base*base)%m)
			if (p&1)
				ans=(ans*base)%m;
		printf("%I64d\n",ans);
	}
	return 0;
}
