#include <cstdio>
#include <cmath>
#define PI 3.1415927
int main(){
	//freopen("2002.in", "r", stdin);
	//freopen("2002.out", "w", stdout);
	double x, y;
	while (scanf("%lf", &x) == 1) {
		y = pow(x, 3) * 4 * PI / 3;
		printf("%.3f\n", y);
	}
}
