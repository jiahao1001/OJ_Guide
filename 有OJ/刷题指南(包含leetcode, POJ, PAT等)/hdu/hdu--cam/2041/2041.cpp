#include <cstdio>

int main(){
	freopen("2041.in", "r", stdin);
	freopen("2041.out", "w", stdout);
	int n, i;
	scanf("%d", &n);
	int a[41];
	a[1] = 0;
	a[2] = 1;
	a[3] = 2;
	for(i = 4; i < 41; i++) {
		a[i] = a[i-1] + a[i-2];
	}
	while(n--) {
		int m;
		scanf("%d", &m);
		printf("%d\n", a[m]);
	}
}
		
