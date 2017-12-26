#include <stdio.h>
int main()
{
	int n,s,c,i;
	scanf("%d",&n);
	printf("PERFECTION OUTPUT\n");
	while (n!=0)
	{
		if (n%2==0)
		{
			c=1;
			s=3+n/2;
		}
		else {
			c=2;
			s=1;
		}
		for (i=3;i*i<=n;i+=c)
		{
			if (n%i==0)
				s+=i+n/i;
		}
		printf("%5d  ",n);
		if (n==1)
			s=0;
		if (s==n)
			printf("PERFECT\n");
		else if (s>n)
			printf("ABUNDANT\n");
		else printf("DEFICIENT\n");
		scanf("%d",&n);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
