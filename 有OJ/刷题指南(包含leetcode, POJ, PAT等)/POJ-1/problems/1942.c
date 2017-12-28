#include<stdio.h>
__int64 zuhe(unsigned int m,unsigned int k) //ÆÕÍ¨¾«¶È
{
	unsigned int i;
	__int64 s=1;
	if (k>m-k)
		k=m-k;
	for (i=1;i<=k;i++)
		s=s*(m+1-i)/i;
	return s;
}
int main()
{
	unsigned int m,n;
	scanf("%u%u",&m,&n);
	while (m!=0 || n!=0)
	{
		printf("%I64d\n",zuhe(m+n,m));
		scanf("%u%u",&m,&n);
	}
	return 0;
}
