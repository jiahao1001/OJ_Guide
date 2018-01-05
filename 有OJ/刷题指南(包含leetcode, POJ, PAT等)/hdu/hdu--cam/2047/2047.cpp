#include <cstdio>

int main() {
	freopen("2047.in", "r", stdin);
	freopen("2047.out", "w", stdout);
	int n, i;
	long long a[41];
	a[1] = 3;
	a[2] = 8;
	for(i = 3; i < 41; i++) {
		a[i] = 2*a[i - 1] + 2*a[i -2];
	}
	while(~scanf("%d", &n)) {
		printf("%I64d\n", a[n]);
	}
}
