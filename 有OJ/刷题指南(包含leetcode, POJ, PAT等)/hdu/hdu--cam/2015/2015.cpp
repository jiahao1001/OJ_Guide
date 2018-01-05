#include <cstdio>
using namespace std;

int main(){
	//freopen("2015.in", "r", stdin);
	//freopen("2015.out", "w", stdout);
	int m, n, i, b, q;
	int ans[101];
	for (i = 0 ; i < 101;  i++) {
		ans[i] = 2 * i;
	} 
	while (scanf("%d %d", &n, &m) == 2) {
		if (n < m) {
			b = (ans[1] + ans[n]) / 2;
			printf("%d\n", b);
		} else {
			int flag(0);
			q = m;
			while (q <= n) {
				b = (ans[q - m + 1] + ans[q]) / 2;
				if(flag == 0) {
					printf("%d", b);
				} else {
					printf(" %d", b);
				}
				q += m;
				flag++;
			}
			if ((q - m) < n) {
				b = (ans[q - m + 1] + ans [n]) / 2;
				printf(" %d\n", b);
			} else {
				printf("\n");
			}
		}
	}
}
			
	
		
		
