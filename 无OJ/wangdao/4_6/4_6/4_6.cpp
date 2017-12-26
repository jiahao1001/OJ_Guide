#include<stdio.h>
int gcd(int a, int b)
{
	while (b != 0)
	{
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}
int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		printf("%d\n", gcd(a, b));
	}
	return 0;
}