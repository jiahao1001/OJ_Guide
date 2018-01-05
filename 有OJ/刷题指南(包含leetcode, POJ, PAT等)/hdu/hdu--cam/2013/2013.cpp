#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	//freopen("2013.in", "r", stdin);
	//freopen("2013.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1) {
		int ans(1);
		for (int i = 1; i < n; i++) {
			ans = 2 * ans + 2;
		}
		printf("%d\n", ans);
	}
}
