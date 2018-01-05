#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	freopen("2008.in", "r", stdin);
	freopen("2008.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1) {
		if(n > 0) {
		double ans[n];
		int a(0), b(0), c(0);
		for(int i = 0; i < n; i ++) {
			scanf("%lf", &ans[i]);
			if (ans[i] < 0) {
				a++;}
			else if (ans[i] == 0) {
				b++;}
			else {
				c++;}
		}
		printf("%d %d %d\n", a, b, c);
	}
	}
}
