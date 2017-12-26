#include<stdio.h>
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int x = 0; x <= 100;x++)
		for (int y = 0; y <= 100 - x; y++)
		{
			int z = 100 - x - y;
			if (x * 5 * 3 + y * 3 * 3 + z <= n * 3)
			{
				printf("x=%d,y=%d,z=%d\n", x, y, z);
			}
		}
	}
	return 0;
}