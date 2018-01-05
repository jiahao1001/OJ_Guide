#include <cstdio>
using namespace std;

int main(){
	freopen("2014.in", "r", stdin);
	freopen("2014.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1) {
		int i = 0, ans[n], max(0), min(100);
		double add(0);
		while (i < n) {
			scanf("%d", &ans[i]);
			add += ans[i];
			if (ans[i] >= max) {
				max = ans[i];
			}
			if (ans[i] <= min) {
				min = ans[i];
			}
			i++;
		}
		double average;
		add = add - max - min;
		average = add / (n - 2);
		printf("%.2lf\n", average);
	}
} 
