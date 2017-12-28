#include <stdio.h>
int main()
{
	int n, i, j;
	scanf("%d", &n);
	if (n == 1) printf("2\n");
	else if (n == 2) printf("4\n");
	else if (n == 3) printf("7\n");
	else if (n == 4) printf("13\n");
	else
	{
		int gjd[4][5000] = { 0 }, len[4] = { 1,1,1,2 };
		gjd[0][0] = 2;
		gjd[1][0] = 4;
		gjd[2][0] = 7;
		gjd[3][0] = 3;
		gjd[3][1] = 1;
		for (i = 4; i<n; ++i)
		{
			for (j = 0; j<len[(i + 3) % 4]; ++j) gjd[i % 4][j] = 2 * gjd[(i + 3) % 4][j] - gjd[i % 4][j];
			for (j = 0; j<len[(i + 3) % 4]; ++j)
			{
				while (gjd[i % 4][j]<0)
				{
					gjd[i % 4][j] += 10;
					gjd[i % 4][j + 1] -= 1;
				}
				while (gjd[i % 4][j] >= 10)
				{
					gjd[i % 4][j] -= 10;
					gjd[i % 4][j + 1] += 1;
				}
			}
			len[i % 4] = len[(i + 3) % 4];
			if (gjd[i % 4][len[i % 4]] != 0) ++len[i % 4];
		}
		for (j = len[(n - 1) % 4] - 1; j >= 0; --j) printf("%d", gjd[(n - 1) % 4][j]);
		printf("\n");
	}
}
