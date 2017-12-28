#include <iostream>
#include <cmath>
using namespace std;
bool prime(int& n)
{
	if (n<2) return false;
	if (n<4) return true;
	if (n == 4) return false;
	int qq = floor(sqrt(n) + 0.5) + 1;
	for (int i = 2; i<qq; ++i) if (n%i == 0) return false;
	return true;
}
int main()
{
	int n;
	cin >> n;
	if (prime(n)) cout << 0;
	else
	{
		int k, t;
		for (k = n - 1; (!prime(k)); --k);
		for (t = n + 1; (!prime(t)); ++t);
		cout << t ;//- k;
	}
}
