#include <cstdio>
#include <cstring> 
using namespace std;
int fac(int n){
	int ans = 1;
	for (int i = 1; i <= n; i++){
		ans= ans * i;
	}
}
int main() {
	freopen("2049.in", "r", stdin);
	freopen("2049.out", "w", stdout);
	int c, m, n;
	int a[21];                               
	a[1] = 0;
	a[2] = 1;  
	for(int i = 3; i <= 20; i++) {
		a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
	}
	scanf("%d", &c);
	while(c--) {
		scanf("%d%d", &m, &n);
		int x(1);
		for(int i = 0; i < m; i++) {
			x *= (n - i);
		}
		x  = x * a[m] / fac(m);
		printf("%d\n", x);
	}
} 
			
