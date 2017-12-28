#include<stdio.h>
__int64 football[50] = {1, 2 ,3};
int main()
{
	int i, j, n;
	for (i = 3; i <= 45; i++)
		football[i] = football[i - 1] + football[i - 2];
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &j);
		printf("Scenario #%d:\n%I64d\n\n", i, football[j]);
	}
	return 0;
}
