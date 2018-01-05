#include <cstdio>

int main(){
	freopen("2045.in", "r", stdin);
	freopen("2045.out", "w", stdout);
	int n;
	long long a[51];
	a[0] = 0;
	a[1] = 3;
	a[2] = a[3] =6;
	for(int i = 4; i < 51; i++) {
		a[i] = a[i -1]+ 2 * a[i - 2];
	}
	while(~scanf("%d", &n)) {
		printf("%I64d\n",a[n]);
	}
}
