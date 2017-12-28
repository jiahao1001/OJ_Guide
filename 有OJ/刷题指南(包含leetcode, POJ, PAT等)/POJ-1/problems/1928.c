#include<stdio.h>
#include<stdlib.h>
struct Peanut{
	int num;
	int x;
	int y;
}peanut[2500];
int cmp(const void *a, const void *b)
{
	struct Peanut x,y;
	x=*(struct Peanut *)a;
	y=*(struct Peanut *)b;
	if (x.num<y.num)
		return 1;
	else if (x.num>y.num)
		return -1;
	else return 0;
}
int fab(int i, int j)
{
	if (i > j)
		return i - j;
	else return j - i;
}
int main()
{
	int i, j, k, n, m, p, q, t, K, a, b;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d%d%d", &m, &n, &K);
		q = 0;
		for (j = 1; j <= m; j++)
		{
			for (k = 1; k <= n; k++)
			{
				scanf("%d", &p);
				if (p != 0)
				{
					peanut[q].num = p;
					peanut[q].x = j;
					peanut[q].y = k;
					q++;
				}
			}
		}
		qsort(peanut, q, sizeof(peanut[0]), cmp);
		p = 0;
		j = 0;
		k = 0;
		a = 0;
		b = peanut[0].y;
		while (j + fab(peanut[k].x, a) + fab(peanut[k].y, b) + peanut[k].x + 1 <= K)
		{
			j += fab(peanut[k].x, a) + fab(peanut[k].y, b) + 1;
			a = peanut[k].x;
			b = peanut[k].y;
			p += peanut[k].num;
			k++;
		}
		printf("%d\n", p);
	}
	return 0;
}
