#include <cstdio>

int main(){
	freopen("2046.in", "r", stdin);
	freopen("2046.out", "w", stdout);
	long long a[51];
	a[1] = 1;
	a[2] = 2;
	for(int i = 3; i < 51; i++) {
		a[i] = a[i -1] + a[i -2];
	}
	int n;
	while (~scanf("%d", &n)) {
		printf("%I64d\n", a[n]);
	}
}		 
