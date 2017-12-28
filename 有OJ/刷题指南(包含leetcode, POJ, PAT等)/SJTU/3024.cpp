#include <iostream>
using namespace std;
int max(int a, int b)
{
	return (a>b) ? a : b;
}
int main()
{
	int m, n, i, j, k, p, w, v, t;
	cin >> n >> m;
	int *pack = new int[m + 1];
	for (i = 0; i <= m; ++i) pack[i] = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> p >> w >> v;
		t = max(w - 1, m - p * w);
		for (j = m; j >= w; --j)
		{
		    for (k=1;k<=p && j-k*w>=0;++k)
		        pack[j] = max(pack[j], pack[j - k*w] + k*v);
		}
	}
	cout << pack[m];
	delete[] pack;
}
