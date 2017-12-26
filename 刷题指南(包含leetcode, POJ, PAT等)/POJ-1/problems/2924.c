#include<stdio.h>
int main()
{
	int t,i;
	__int64 n,m;
	scanf("%d",&t);
	for (i=1;i<=t;i++)
	{
		scanf("%I64d%I64d",&n,&m);
		printf("Scenario #%d:\n%I64d\n\n",i,(n+m)*(m+1-n)/2);
	}
	return 0;
}
