#include <stdio.h>
int prime (int n)
{
	int i=3;
	while (i*i<=n)
	{
		if (n%i==0)
			return 0;
		i+=2;
	}
	return 1;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	while (n!=0)
	{
		for (i=3;i<=n/2;i+=2)
		{
			if (prime(i) && prime(n-i))
			{
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
		}
		scanf("%d",&n);
	}
	return 0;
}
