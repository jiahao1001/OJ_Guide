#include <cstdio>
using namespace std;
void qsort(int* a, int l, int r)
{
	if (l >= r) return;
	int i = l, j = r, k = a[r];
	a[r] = a[l]; a[l] = k;
	while (i<j)
	{
		while ((i<j) && (a[j] >= k)) --j;
		a[i] = a[j];
		while ((i<j) && (a[i] <= k)) ++i;
		a[j] = a[i];
	}
	a[i] = k;
	qsort(a, l, i - 1);
	qsort(a, i + 1, r);
}
int main()
{
	int n, i;
	scanf("%d", &n);
	int* x = new int[n];
	for (i = 0; i<n; ++i) scanf("%d", &x[i]);
	qsort(x, 0, n - 1);
	for (i = 0; i<n; ++i) printf("%d ", x[i]);
	delete[] x;
}
