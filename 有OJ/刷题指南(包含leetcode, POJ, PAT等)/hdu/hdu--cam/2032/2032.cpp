#include <cstdio>

int main(){
	freopen("2032.in", "r", stdin);
	freopen("2032.out", "w", stdout);
	int a[31][31];
	int n;
	while(~scanf("%d", &n)) {
		int i, j;
		for(i = 1; i <= n; i++) {
			a[i][1] = 1;
			a[i][i] = 1;
		}
		for(i = 3; i <= n; i++) {
			for(j = 2; j < i; j++) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
		for (i = 1; i <= n; i++) {
			printf("%d", a[1][1]);
			for (j = 2; j <= i; j++) {
				printf(" %d", a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
