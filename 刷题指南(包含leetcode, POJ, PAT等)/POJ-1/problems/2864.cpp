#include<stdio.h>
bool student[500][100];
int main()
{
	int i, j, n, d;
	scanf("%d%d", &n, &d);
	while (n != 0 || d != 0)
	{
		for (i = 0; i < d; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &student[i][j]);
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < d; i++)
				if (student[i][j] == false)
					break;
			if (i == d)
				break;
		}
		if (j < n)
			printf("yes\n");
		else printf("no\n");
		scanf("%d%d", &n, &d);
	}
	return 0;
}
