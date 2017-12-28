#include <iostream>
using namespace std;
void minize(long long& a, long long& b, long long& c)
{
	long long t;
	if (a>b) { t = b; b = a; a = t; }
	if (a>c) { t = c; c = a; a = t; }
	if (b>c) { t = c; c = b; b = t; }
}
long long max(long long a, long long b, long long c)
{
	long long t = a;
	if (t<b) t = b;
	if (t<c) t = c;
	return t;
}
void calc(long long* q, int n, long long& t, long long& w)
{
	t = 0; w = 0;
	int i;
	for (i = 0; i<n; ++i)
	{
		t += q[i];
		w += q[i] * (n - 1 - i);
	}
}
void process_1(long long* q, int n)
{
	int i, l[3]; long long t = 0, tp, w = 0, wp;
	long long* qq[3];
	for (i = 0; i<3; ++i)
	{
		l[i] = (n + 2 - i) / 3;
		qq[i] = new long long[l[i]];
	}
	for (i = 0; i<n; ++i) qq[i % 3][i / 3] = q[i];
	for (i = 0; i<3; ++i)
	{
		calc(qq[i], l[i], tp, wp);
		w += wp;
		if (t<tp) t = tp;
	}
	cout << w << ' ' << t << endl;
	for (i = 0; i<3; ++i)
	{
		delete[] qq[i];
	}
}
void process_2(long long *q, int n)
{
	int i; long long w = 0, t = 0;
	for (i = 0; i<n - 2; ++i)
	{
		minize(q[i], q[i + 1], q[i + 2]);
		if (i == n - 3) t += q[i + 2];
		else
		{
			w += q[i] * (n - 3 - i);
			t += q[i];
			q[i + 1] -= q[i];
			q[i + 2] -= q[i];
			q[i] = 0;
		}
	}
	cout << w << ' ' << t;
}
int main()
{
	int n, i;
	cin >> n;
	long long *q = new long long[n];
	for (i = 0; i<n; ++i) cin >> q[i];
	if (n == 0)
	{
		cout << "0 0\n0 0";
		return 0;
	}
	else if (n == 1)
	{
		cout << "0 " << q[0] << endl << "0 " << q[0];
		return 0;
	}
	else if (n == 2)
	{
		cout << "0 " << ((q[0]>q[1]) ? q[0] : q[1]) << endl << "0 " << ((q[0]>q[1]) ? q[0] : q[1]);
		return 0;
	}
	process_1(q, n);
	process_2(q, n);
	delete[] q;
}
