#include<stdio.h>
int main()
{
	int n, i, m;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		printf("%d %d QUARTER(S), ", i, m / 25);
		m -= m / 25 * 25;
		printf("%d DIME(S), ", m / 10);
		m -= m / 10 * 10;
		printf("%d NICKEL(S), ", m / 5);
		m -= m / 5 * 5;
		printf("%d PENNY(S)\n", m);
	}
	return 0;
}
