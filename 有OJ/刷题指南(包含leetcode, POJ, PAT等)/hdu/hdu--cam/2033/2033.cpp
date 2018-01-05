#include <cstdio>

int main(){
	freopen("2033.in", "r", stdin);
	freopen("2033.out", "w", stdout);
	int n, a[6], i, b[3];
	scanf("%d", &n);
	while (n > 0) {
		for (i = 0; i < 6; i++) {
			scanf("%d", &a[i]);
		}
		b[0] = a[0] + a[3];
		b[1] = a[1] + a[4];
		b[2] = a[2] + a[5];
		while(b[2] > 60) {
			b[2] -= 60;
			b[1]++;
		}
		while(b[1] > 60) {
			b[1] -= 60;
			b[0]++;
		}
		printf("%d %d %d\n", b[0], b[1], b[2]);
	n--;
	}
}
		 
