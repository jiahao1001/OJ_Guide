#include<stdio.h>
__int64 gcd(__int64 a,__int64 b)//返回a,b的最大公约数a,b>=0
{
	if (b==0)
		return a;
	else return gcd(b,a%b);
}
int main()
{
	int machine,wheel;
	__int64 jackpot,j,k;
	int m,i;
	scanf("%d",&machine);
	for (m=0;m<machine;m++)
	{
		scanf("%d",&wheel);
		scanf("%I64d",&jackpot);
		for (i=1;i<wheel;i++)
		{
			scanf("%I64d",&j);
			k=gcd(jackpot,j);
			jackpot=jackpot*j/k;
		}
		if (jackpot>1000000000)
			printf("More than a billion.\n");
		else printf("%d\n",jackpot);
	}
	return 0;
}
