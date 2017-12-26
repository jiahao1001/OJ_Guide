#include <stdio.h>
int main()
{
	int n,m,i,j,k;
	scanf("%d",&n);
	while (n!=0)
	{
		m=0;
		i=1;
		j=n;
		while (j)
		{
			k=j%10;
			if (k>4)
				k--;
			m+=i*k;
			i*=9;
			j/=10;
		}
		printf("%d: %d\n",n,m);
		scanf("%d",&n);
	}
	return 0;
}
