#include <cstdio>
#include <iostream>
using namespace std;

int main () {
	freopen("2006.in", "r", stdin);
	freopen("2006.out", "w", stdout);
	int n, i, x;
	while (scanf("%d", &n) == 1) {
			int a[n];
			x = 1;
			for (i = 0; i < n; i++) {
				cin >> a[i];
				if (a[i] & 1) {
				x *= a[i];
				}
			}
			printf("%d\n", x);
	}
}
						
