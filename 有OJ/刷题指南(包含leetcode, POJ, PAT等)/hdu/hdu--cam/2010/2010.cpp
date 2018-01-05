#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	freopen("2010.in", "r", stdin);
	freopen("2010.out", "w", stdout);
	int m, n, i, j;
	while (scanf("%d %d", &m, &n) == 2) {
		int a, b, c, ans, t(0);
		j = 0; 
		for (i = m; i <= n; i++) {
			a = i / 100;
			b = (i % 100) / 10;
			c = i % 10;
			ans = a*a*a + b*b*b + c*c*c;
			if (i == ans) {
				j++;
				if (t == 0){
				printf("%d", i);
				t++;
				}
				else{		
				printf(" %d", i);
				}
			}
		}
		if (j == 0){
			printf("no");
		}
		printf("\n");
	}
}
