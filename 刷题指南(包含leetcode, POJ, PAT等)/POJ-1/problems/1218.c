#include <stdio.h>
#include <math.h>
int main()
{
	int n,k,i=1;
	scanf("%d",&n);
	while (i<=n)
	{
		scanf("%d",&k);
		printf("%d\n",(int)sqrt(k));
		i++;
	}
	return 0;
}
