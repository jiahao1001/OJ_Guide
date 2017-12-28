#include <cstdio>
int n, k, base = 1;
const long long BASE = 1000000007;
long long res = 0;
class Bit
{
public:
	int* a;
	int size;
	Bit(int n)
	{
		size = n;
		a = new int[n + 1];
		for (int i = 0; i <= n; i++)
			a[i] = 0;
	}
	~Bit()
	{
		delete[] a;
	}
	long long sum(int pos)
	{
		long long  res = 0;
		while (pos>0)
		{
			res += a[pos];
			res %= BASE;
			pos -= pos&(-pos);
		}
		return res;
	}
	void add(int pos, int num)
	{
		num %= BASE;
		while (pos <= size)
		{
			a[pos] += num;
			a[pos] %= BASE;
			pos += pos&(-pos);
		}
	}
};
void qsort(int* t, int* p, int l, int r)
{
	if (l >= r) return;
	int i = l, j = r, v = t[i], q = p[i];
	while (i<j)
	{
		while ((i<j) && (t[j] >= v)) --j;
		t[i] = t[j]; p[i] = p[j];
		while ((i<j) && (t[i] <= v)) ++i;
		t[j] = t[i]; p[j] = p[i];
	}
	t[i] = v; p[i] = q;
	qsort(t, p, l, i - 1);
	qsort(t, p, i + 1, r);
}
int main()
{
	scanf("%d %d", &n, &k);
	int i, x, tmp, j, kk;
	for (i = 2; i <= k - 1; ++i) base *= i;
	int *a = new int[n], *b = new int[n], *c = new int[n];
	for (i = 0; i<n; ++i)
	{
		scanf("%d", &a[i]);
		b[i] = i;
	}
	qsort(a, b, 0, n - 1);
	j = 1; c[b[0]] = 1;
	for (i = 1; i<n; ++i)
	{
		if (a[i] != a[i - 1]) ++j;
		c[b[i]] = j;
	}
	Bit** d = new Bit*[k + 1];
	for (i = 1; i <= k; ++i) d[i] = new Bit(j);
	for (i = n - 1; i >= 0; --i)
	{
		d[1]->add(c[i], 1);
		for (kk = 2; kk <= k; ++kk)
		{
			d[kk]->add(c[i], d[kk - 1]->sum(c[i] - 1));
		}
	}
	res = d[k]->sum(j) % BASE;
	printf("%lld", res);
	delete[] a;
	delete[] b;
	delete[] c;
	for (i = 1; i <= k; ++i) delete d[i];
	delete[] d;
}

