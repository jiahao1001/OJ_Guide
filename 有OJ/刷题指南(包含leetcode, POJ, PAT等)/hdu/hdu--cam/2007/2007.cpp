#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	freopen("2007.in", "r", stdin);
	freopen("2007.out", "w", stdout);
	int x1, x2;
	while(scanf("%d%d", &x1, &x2) == 2) {
		int y1(0), y2(0), t;
		if (x1 > x2){
			t = x1;
			x1 = x2;
			x2= t;
		}
		if (x1 % 2 == 0){
			int i = x1;
			while (i <= x2){
				y1 += i * i;
				i = i + 2;
			}
			i = x1 + 1;
			while (i <= x2){
				y2 += i * i * i;
				i = i + 2;
			}
		}
		else {
			int i = x1;
			while (i <= x2){
				y2 += i * i * i;
				i = i + 2;
			}
			i = x1 + 1;
			while (i <= x2){
				y1 += i * i;
				i = i + 2;
			}
		}
	printf("%d %d\n", y1, y2);}
	}
			
