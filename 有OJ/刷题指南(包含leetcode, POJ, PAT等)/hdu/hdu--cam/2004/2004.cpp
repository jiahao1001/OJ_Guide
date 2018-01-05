#include  <cstdio>
#include <cmath>
int main(){
	freopen("2004.in", "r", stdin);
	freopen("2004.out", "w", stdout);
	double x;
	while (scanf("%lf", &x) == 1) {
		if (x < 0 || x > 100) {
			printf("Score is error!\n");
		} else if(x >= 90) {
			printf("A\n");
		} else if(x >= 80) {
			printf("B\n");
		} else if(x >= 70) {
			printf("C\n");
		} else if(x >= 60) {
			printf("D\n");
		} else { 
			printf("E\n");
		}
	}
}
