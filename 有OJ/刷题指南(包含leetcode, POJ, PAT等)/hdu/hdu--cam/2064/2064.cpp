#include <cstdio>
#include <algorithm>

const int N = 36;

long long ans[N];

int main() {
	freopen("2064.in", "r", stdin);
	freopen("2064.out", "w", stdout);
	ans[0] = 1;
	for (int i = 1; i < N; i++) {
		ans[i] = ans[i - 1] * 3;
	}
	int n;
	while (scanf("%d", &n) == 1) {
		printf("%I64d\n", ans[n] - 1);
	}
} 
