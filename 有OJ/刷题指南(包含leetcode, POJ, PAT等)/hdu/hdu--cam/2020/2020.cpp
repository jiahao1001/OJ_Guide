#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	freopen("2020.in", "r", stdin);
	freopen("2020.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1) {
		if(!n) break;
		int a[n], b[n], i, j, min;
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			b[i] = abs(a[i]);
		}
		for (j = 0; j < n - 1; j++) {
			for (i = 0; i < n - 1 - j; i++) {
				if (b[i] < b[i + 1]){
					min = b[i];
					b[i] = b[i + 1];
					b[i + 1] = min;
					min = a[i];
					a[i] = a[i + 1];
					a[i + 1] = min;
				}
			}
		}
		printf("%d", a[0]);
		for(i = 1; i < n; i++ ) {
			printf(" %d", a[i]);
		}
		printf("\n");
	}
} 
			
