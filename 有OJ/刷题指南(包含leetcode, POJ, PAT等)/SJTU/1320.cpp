#include <iostream>
using namespace std;
int max(int& a, int& b)
{
	return ((a>b) ? a : b);
}
int main()
{
	int n, i, j;
	cin >> n;
	int** x = new int*[n];
	for (i = 0; i<n; ++i)
	{
		x[i] = new int[i + 1];
		for (j = 0; j <= i; ++j) cin >> x[i][j];
	}
	for (i = n - 2; i >= 0; --i) for (j = 0; j <= i; ++j) x[i][j] += max(x[i + 1][j], x[i + 1][j + 1]);
	cout << x[0][0];
	for (i = 0; i<n; ++i) delete[] x[i];
	delete[] x;
}
