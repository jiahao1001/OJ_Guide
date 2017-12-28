#include <iostream>
using namespace std;
int main()
{
	int a, b, n;
	cin >> a >> b >> n;
	int data[51], i;
	data[0] = data[1] = 1;
	for (i = 2; i<51; ++i)
	{
		data[i] = (data[i - 2] * b + data[i - 1] * a) % 7;
		if ((data[i] == 1) && (data[i - 1] == 1)) break;
	}
	i -= 1;
	cout << data[(n - 1) % i];
}
