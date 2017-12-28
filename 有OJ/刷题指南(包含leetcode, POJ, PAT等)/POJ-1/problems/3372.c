#include <stdio.h>
int n;
int main ()
{
	while (scanf("%d",&n)!=EOF)
	{
		while (n%2==0)
			n=n>>1;
		if (n==1)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
