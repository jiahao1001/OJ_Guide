#include <iostream>
using namespace std;
int main()
{
	int n, i, t;
	cin >> n;
	for (i = 0; i<n; ++i)
	{
		cin >> t;
		if (t>0) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
