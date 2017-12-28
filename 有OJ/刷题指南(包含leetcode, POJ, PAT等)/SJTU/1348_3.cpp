#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;

struct person {
	int sex;
	int time;
};

bool cmp(person a, person b) { return a.time<b.time; }

int main() {
	queue<int> boy, girl;
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i<n; ++i) cin >> a[i];
	int m;
	cin >> m;
	person b[m];
	for (int i = 0; i<m; ++i) cin >> b[i].sex >> b[i].time;
	sort(b, b + m, cmp);
	//for(int i=0;i<m;++i) cout<<b[i].sex<<b[i].time<<endl;
	int boy_num = 0, girl_num = 0;
	for (int i = 0; i<m; ++i) {
		if (b[i].sex == 1) {
			boy.push(b[i].time);
			++boy_num;
		}
		if (b[i].sex == 2) {
			girl.push(b[i].time);
			++girl_num;
		}
	}
	long long current_time = 0;
	double boy_wait = 0, girl_wait = 0;
	int tmp;
	for (int i = 0; i<n; ++i) { //曲子 (时间)
								//cout << "time " << current_time << endl;
		while (!boy.empty() && !girl.empty() && boy.front() <= current_time&&girl.front() <= current_time) {
			boy_wait += current_time - boy.front();
			girl_wait += current_time - girl.front();
			boy.pop(); girl.pop();
		}
		if (i != n - 1) current_time += a[i];
	}
	//最后一首歌开始 剩下男女离去
	while (!boy.empty()) {
		boy_wait += current_time - boy.front();
		boy.pop();
	}
	while (!girl.empty()) {
		girl_wait += current_time - girl.front();
		girl.pop();
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << boy_wait / boy_num << ' ' << girl_wait / girl_num;
	return 0;
}
