#include <cstdio>
#include <cstdlib>
using namespace std;

int num(int);
int main(){
	freopen("2021.in", "r", stdin);
	freopen("2021.out", "w", stdout);
	int n;
	while(scanf("%d", &n) == 1) {
		if(!n) break;
		int add(0),i, t;
		for(i = 0; i < n; i++) {
			scanf("%d", &t);
			add += num(t);
		}
		printf("%d\n", add);
	}
}
int num(int x) {
	int a, b, c, d, e, f, g, num;
	a = x / 100;
	b = (x - 100*a)/50;
	c = (x - 100*a - 50*b)/10;
	g = x - 100*a - 50*b - 10*c;
	d = g/5;
	e = (g - 5*d)/2;
	f = g - 5*d - 2*e;
	num = a+b+c+d+e+f;
	return num;
}
	
	 
