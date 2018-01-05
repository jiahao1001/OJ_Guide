#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	//freopen("2001.in", "r", stdin);
	//freopen("2001.out", "w", stdout);
    double a, b, c, d, x;
	while (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) == 4) {
		x = pow(a - c, 2) + pow(b - d, 2);
		x = sqrt(x);
		printf("%.2f\n", x);
    }
}
