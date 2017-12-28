#include <stdio.h>
int main()
{
	unsigned l, m, n, i, j, k, mid, c, p;
	scanf("%d %d %d", &l, &n, &m);
	unsigned *data = new unsigned[n + 2];
	data[0] = 0; data[n + 1] = l;
	for (i = 1; i <= n; ++i) scanf("%d", &data[i]);
	i = 0; j = l;
	while (i <= j)
	{
		mid = (i + j) / 2;
		c = 0; p = 0;
		for (k = 1; k <= n; ++k) if (data[k] - data[p]<mid) ++c; else p = k;
		if (c <= m) i = mid + 1; else j = mid - 1;
	}
	printf("%d", j);
	delete[] data;
}
