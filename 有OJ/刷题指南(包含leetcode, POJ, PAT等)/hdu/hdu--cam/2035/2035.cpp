#include <cstdio>
#include <cmath>

int main(){
	freopen("2035.in", "r", stdin);
	freopen("2035.out", "w", stdout);
	int m, n, i, x;
	while (~scanf("%d%d", &m, &n)) {
		x= 1;
		if(m == 0 && n == 0)break;
		for(i = 0; i < n; i++) {
			x = x * m % 1000;
		}
		printf("%d\n", x);
	}
}
	 	
