#include <iostream>
using namespace std;
unsigned long long mi(unsigned long long k, unsigned long long n)
{
	if (n == 1) return 0;
	if (k == 0) return 1;
	if (k == 1) return 10 % n;
	if (k == 2) return 100 % n;
	unsigned long long tmp = mi(k / 2, n);
	if (k % 2) return ((tmp%n)*(tmp%n) * 10) % n;
	else return ((tmp%n)*(tmp%n)) % n;
}
int main()
{
	unsigned long long m, n, k, x;
	cin >> n >> m >> k >> x;
	m %= n;
	cout << (x + m*mi(k, n)) % n;
}
