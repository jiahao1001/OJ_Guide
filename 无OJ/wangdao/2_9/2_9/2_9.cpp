#include<stdio.h>
#define OFFSET 500000
int Hash[10000001];
int main()
{
	int n, m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		for (int i = -500000; i <= 500000; i++)
		{
			Hash[i + OFFSET] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			Hash[x + OFFSET] = 1;
		}
		for (int i = 500000; i >= -500000; i--)
		{
			if (Hash[i + OFFSET] == 1)
			{
				printf("%d", i);
				m--;
				if (m != 0)
					printf(" ");
				else
				{
					printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}