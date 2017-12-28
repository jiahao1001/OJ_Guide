#include <iostream>
using namespace std;
int max(int a, int b)
{
	return (a>b) ? a : b;
}
int main()
{
	int v, n, i, j, c, w;
	cin >> v >> n;
	int *pack = new int[v + 1];
	for (i = 0; i <= v; ++i) pack[i] = 0;
	for (i = 0; i<n; ++i)
	{
		cin >> c >> w;
		for (j = c; j <= v; ++j) pack[j] = max(pack[j], pack[j - c] + w);
	}
	cout << pack[v];
	delete[] pack;
}
