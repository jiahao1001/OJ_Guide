#include <cstdio>
#include <cmath>
int main(){
	freopen("2003.in", "r", stdin);
	freopen("2003.out", "w", stdout);
	double x, y;
	while (scanf("%lf", &x) == 1) {
		y = fabs(x);
		printf("%.2f\n", y);
	}
}
