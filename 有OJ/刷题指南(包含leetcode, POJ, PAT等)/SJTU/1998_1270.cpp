#include <iostream>
using namespace std;
void qsort(int* a, int l, int r)
{
	if (l >= r) return;
	int i = l, j = r, k = a[l];
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
	int n, i, t; unsigned long sum = 0;
	cin >> n;
	int* x = new int[n];
	for (i = 0; i<n; ++i) cin >> x[i];
	qsort(x, 0, n - 1);
	t = n / 2;
	for (i = 0; i<t; ++i) sum += (x[n - 1 - i] - x[i]);
	cout << sum;
}
