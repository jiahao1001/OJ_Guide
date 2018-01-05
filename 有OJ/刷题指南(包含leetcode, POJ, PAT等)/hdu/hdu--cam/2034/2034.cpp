
#include <cstdio>

int main(){
	freopen("2034.in", "r", stdin);
	freopen("2034.out", "w", stdout);
	int m, n, i, t;
	int a[101], b[101], c[201];
	while(scanf("%d%d", &n, &m) == 2) {
		if(m == 0 && n == 0) break;
		for(i =0; i < n; i++)
		scanf("%d", &a[i]);
		for(i = 0; i < m; i++)
		scanf("%d", &b[i]);
		int j, k = 0;
		for( i = 1; i < n; i++)
			for (j = 0; j < n - i; j++){
				t = a[j];
				if (a[j] > a[j+1]) {
					a[j] = a[j+1];
					a[j+1] = t;
				}
			}
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				if(a[i] == b[j]) break;
			}
			if(j == m) {
				c[k] = a[i];
				k++;
			}
		}
		for(i = 0; i < k; i++) {
			printf("%d ", c[i]);
		}
		if (i == 0) {
			printf("NUIL\n");
		} else {
			printf("\n");
		}
	}
}
					
