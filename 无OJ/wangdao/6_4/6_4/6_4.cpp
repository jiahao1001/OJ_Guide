#include<stdio.h>
#include<string.h>
long long F(int num)
{
	if (num == 1)return 2;
	else return 3 * F(num - 1) + 2;
}
int main()
{
	int n;
	long long t;
	while (scanf("%d", &n) != EOF)
	{
		printf("%I64d\n", F(n));
	}
	return 0;
}