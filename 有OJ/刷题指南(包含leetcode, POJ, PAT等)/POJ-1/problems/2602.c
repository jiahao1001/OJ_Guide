#include<stdio.h>
int main()
{
	int n,i,j;
	char c[1000000];
	scanf("%d\n",&n);
	for (i=n-1;i>=0;i--)
	{
		c[i]=getchar();
		getchar();
		c[i]+=getchar()-'0';
		for (j=i;c[j]>'9';)
		{
			c[j]-=10;
			c[++j]++;
		}
		getchar();
	}
	for (i=n-1;i>=0;i--)
		putchar(c[i]);
	putchar('\n');
	return 0;
}
