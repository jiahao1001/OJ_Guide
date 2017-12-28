#include<stdio.h>
int num[350] = {0 , 3};
int main()
{
	int n, i, m, sum = 3;
	for (i = 2; i <= 300 ; i++)
	{
		sum += i + 1;
		num[i] = num[i - 1] + sum * i;
	}
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		printf("%d %d %d\n", i, m, num[m]);
	}
	return 0;
}
