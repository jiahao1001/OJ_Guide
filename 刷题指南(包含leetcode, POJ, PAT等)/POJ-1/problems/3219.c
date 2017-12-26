#include <stdio.h>
int num(int p)
{
	int sum=0;
	while (p>0)
	{
		p/=2;
		sum+=p;
	}
	return sum;
}
int main()
{
	int n,k;
	int a,b,c;
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		a=num(n);
		b=num(k);
		c=num(n-k);
		if (a>b+c)
			printf("0\n");
		else printf("1\n");
	}
    return 0;
}
