#include<stdio.h>
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF&&n!=0)
	{
		int Hash[101] = { 0 };
		for (int i = 0; i< n; i++)
		{
			int x;
			scanf("%d", &x);
			Hash[x]++;
		}
		int x;
		scanf("%d", &x);
		printf("%d\n", Hash[x]);
	}
	return 0;
}