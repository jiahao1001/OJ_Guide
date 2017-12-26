#include<stdio.h>
int main()
{
	int i,j,n;
	scanf("%d",&n);
	while (n)
	{
		i=9;
		j=1;
		while (n-2*i>0)
		{
			n-=2*i;
			i*=10;
			j*=10;
		}
		j+=((n%i==0) ? i:n%i)-1;
		printf("%d",j);
		if (n-i<=0)
			j/=10;
		while (j)
		{
			printf("%d",j%10);
			j/=10;
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
