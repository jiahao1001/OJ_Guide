#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int n, i, t, y, count = 0;
	queue<int> p[2];
	int num[2] = { 0,0 };
	cin >> n;
	for (i = 0; i<n; ++i)
	{
		cin >> t >> y;
		p[t].push(y);
		++num[t];
	}
	t = 0;
	double wait[2] = { 0,0 };
	while (count<n)
	{
		int tmp = 0;
		while (tmp<8 && !p[0].empty() && p[0].front() <= t)
		{
			wait[0] += t - p[0].front();
			++tmp;
			p[0].pop();
		}
		while (tmp<10 && !p[1].empty() && p[1].front() <= t)
		{
			wait[1] += t - p[1].front();
			++tmp;
			p[1].pop();
		}
		while (tmp<10 && !p[0].empty() && p[0].front() <= t)
		{
			wait[0] += t - p[0].front();
			++tmp;
			p[0].pop();
		}
		count += tmp;
		t += 10;
	}
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	cout << wait[0] / num[0] << ' ' << wait[1] / num[1];
}
