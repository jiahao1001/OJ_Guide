#include<iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	long long * const queue = new long long[num];
	long long time1 = 0ll, time2 = 0ll, time3 = 0ll, time = 0ll, a;
	long long tot1 = 0ll, tot2 = 0ll, tot3 = 0ll, tot = 0ll, b;
	for (int i = 0; i < num; ++i)cin >> queue[i];
	int len1 = num / 3 + (num % 3 > 0), len2 = num / 3 + (num % 3 > 1), len3 = num / 3;
	long long * const que1 = new long long[len1];
	long long * const que2 = new long long[len2];
	long long * const que3 = new long long[len3];
	for (int i = 0; i < num; ++i)
	{
		switch (i % 3)
		{
		case 0:que1[i / 3] = queue[i]; break;
		case 1:que2[i / 3] = queue[i]; break;
		case 2:que3[i / 3] = queue[i]; break;
		default:
			break;
		}
	}
	for (int i = 0; i < len1; ++i)
	{
		time1 += que1[i];
		tot1 += (que1[i] * (len1 - i - 1));
	}
	for (int i = 0; i < len2; ++i)
	{
		time2 += que2[i];
		tot2 += (que2[i] * (len2 - i - 1));
	}
	for (int i = 0; i < len3; ++i)
	{
		time3 += que3[i];
		tot3 += (que3[i] * (len3 - i - 1));
	}
	a = tot1 + tot2 + tot3;
	b = (time1 > time2 ? time1 : time2)>time3 ? (time1>time2 ? time1 : time2) : time3;
	cout << a << ' ' << b << endl;
	if (num == 1) { time = queue[0]; }
	else if (num == 2) { time = (queue[0] > queue[1] ? queue[0] : queue[1]); }
	else {
		for (int i = 0; i < num - 2; ++i)
		{
			if (i == num - 3)
			{
				if (queue[i] > queue[i + 1]) { queue[i] ^= queue[i + 1]; queue[i + 1] ^= queue[i]; queue[i] ^= queue[i + 1]; }
				if (queue[i] > queue[i + 2]) { queue[i] ^= queue[i + 2]; queue[i + 2] ^= queue[i]; queue[i] ^= queue[i + 2]; }
				if (queue[i + 1] > queue[i + 2]) { queue[i + 1] ^= queue[i + 2]; queue[i + 2] ^= queue[i + 1]; queue[i + 1] ^= queue[i + 2]; }
				time += queue[i + 2];
			}

			else
			{
				if (queue[i] > queue[i + 1]) { queue[i] ^= queue[i + 1]; queue[i + 1] ^= queue[i]; queue[i] ^= queue[i + 1]; }
				if (queue[i] > queue[i + 2]) { queue[i] ^= queue[i + 2]; queue[i + 2] ^= queue[i]; queue[i] ^= queue[i + 2]; }
				if (queue[i + 1] > queue[i + 2]) { queue[i + 1] ^= queue[i + 2]; queue[i + 2] ^= queue[i + 1]; queue[i + 1] ^= queue[i + 2]; }
				tot += (queue[i] * (num - 3 - i));
				time += queue[i];
				queue[i + 1] -= queue[i]; queue[i + 2] -= queue[i]; queue[i] = 0;
			}
			//for (int j = 0; j < num; ++j)cout << queue[j];
			//cout << endl;
		}
	}
	cout << tot << ' ' << time;
	delete[]queue;
	delete[]que1;
	delete[]que2;
	delete[]que3;
	//system("pause");
	return 0;
}
