#include<stdio.h>
int main()
{
	char a[11], b[11];
	while (scanf("%s%s", a, b) != EOF)
	{
		int ans = 0;
		for (int i = 0; a[i] != 0; i++)
		{
			for (int j = 0; b[j] != 0; j++)
			{
				ans += (a[i] - '0')*(b[j] - '0');
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}