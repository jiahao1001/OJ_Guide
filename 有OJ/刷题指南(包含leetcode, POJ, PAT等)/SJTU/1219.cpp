#include <stdio.h>
long long *assist;
long long count = 0;
void mergesort(long long* t, int l, int r)
{
	if (l >= r) return;
	int mid = (l + r) / 2;
	mergesort(t, l, mid);
	mergesort(t, mid + 1, r);
	int i = mid, j = r, cur = 0;
	while (i >= l && j>mid)
	{
		while (j>mid && t[i] - t[j] <= t[j]) --j;
		count += j - mid;
		--i;
	}
	i = l;
	j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (t[i]>t[j]) assist[cur++] = t[j++];
		else assist[cur++] = t[i++];
	}
	while (i <= mid) assist[cur++] = t[i++];
	while (j <= r) assist[cur++] = t[j++];
	for (i = l; i <= r; ++i) t[i] = assist[i - l];
}
int main()
{
	int n, i;
	scanf("%d", &n);
	long long *a = new long long[n];
	assist = new long long[n];
	for (i = 0; i<n; ++i) scanf("%lld", &a[i]);
	mergesort(a, 0, n - 1);
	printf("%lld", count);
	delete[] a;
	delete[] assist;
}
