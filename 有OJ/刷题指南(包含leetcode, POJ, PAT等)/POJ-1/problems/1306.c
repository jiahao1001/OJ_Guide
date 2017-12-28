#include<stdio.h>
__int64 zuhe(int m,int k)
{
	int i;
	__int64 s=1;
	if (k>m-k)
		k=m-k;
	for (i=1;i<=k;i++)
		s=s*(m+1-i)/i;
	return s;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (n!=0 || m!=0)
	{
		printf("%d things taken %d at a time is %I64d exactly.\n",n,m,zuhe(n,m));
		scanf("%d%d",&n,&m);
	}
	return 0;
}
