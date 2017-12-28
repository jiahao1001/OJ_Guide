#include <iostream>
using namespace std;
int query(int* c, int p)
{
	if (p == 0) return 0;
	int res = 0;
	for (int t = p; t; t -= (t&-t)) res += c[t];
	return res;
}
void inc(int* c, int p, int n)
{
	for (int t = p; t <= n; t += (t&-t)) ++c[t];
}
int main()
{
	int n, i, *c, *b; unsigned long long res = 0;
	cin >> n;
	b = new int[n];
	c = new int[n + 1];
	for (i = 0; i <= n; ++i) c[i] = 0;
	for (i = 0; i<n; ++i) cin >> b[i];
	for (i = n - 1; i >= 0; --i)
	{
		res += query(c, b[i]);
		inc(c, b[i], n);
	}
	cout << res;
	delete[] b;
	delete[] c;
}
