#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	freopen("2009.in", "r", stdin);
	freopen("2009.out", "w", stdout);
	int  m;
	float n;
	while (scanf("%f %d", &n, &m) == 2) {
		float ans(n);
		for (int i = 1; i < m; i++) {
			n = sqrt(n);
			ans += n;
		}
		printf("%.2f\n", ans);
	}
}
                              
