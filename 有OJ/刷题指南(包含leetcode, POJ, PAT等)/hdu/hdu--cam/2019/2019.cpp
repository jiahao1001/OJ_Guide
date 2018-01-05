#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	freopen("2019.in", "r", stdin);
	freopen("2019.out", "w", stdout);
	int m, n, t;
	while (scanf("%d %d", &n, &m) == 2) {
		int flag = 0;
		if (m == 0 && n ==0) break;
		if (!n) {
			printf("%d\n", m);
		} else {
		scanf("%d", &t);
		if (t > m) {
			printf("%d %d", m, t);
		} else {
			printf("%d", t);
		}
		for (int i = 1; i < n; i++) {
			scanf("%d", &t);
			if (t > m && flag == 0) {
				printf(" %d", m);
				flag = 1;
			}
			printf(" %d", t);
		}
		printf("\n");
	}
}
}
				
	
