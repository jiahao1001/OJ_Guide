#include <stdio.h>
int main()
{
	int p[10000]={1},i;
	for (i=1;i<10000;i++)
	{
		p[i]=p[i-1]*i;
		while (p[i]%10==0)
			p[i]/=10;
		p[i]%=100000;
	}
	while (scanf("%d",&i)!=EOF)
		printf("%5d -> %d\n",i,p[i]%10);
	return 0;
}
