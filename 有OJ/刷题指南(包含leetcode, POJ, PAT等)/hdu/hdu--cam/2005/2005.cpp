#include <cstdio>
#include <cmath>
using namespace std;

int data[ ][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
					{0,31,29,31,30,31,30,31,31,30,31,30,31}};
int main(){
	freopen("2005.in", "r", stdin);
	freopen("2005.out", "w", stdout);
	int a, b, c, d;
	int *p, *j;
	while (scanf("%d/%d/%d", &a, &b, &c) == 3) {
		p = data[0];
		d = c;
	    int i = (a % 4 == 0 && a % 100 != 0 || a % 400 == 0);
	    if (i) {
			p += 13;
		}
		j = p + b;
		while (p < j) {
			d += *p;
			p++;
		}
		printf("%d\n", d);
	}
}
				
		
