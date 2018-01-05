#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	//freopen("2018.in", "r", stdin);
	//freopen("2018.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1) {
		if (!n) break;
		int y1(0), y2(0), y3(0), y4(1), t(0);
		for (int i = 1; i < n; i++) {
			y4 = y3 + y4;
			y3 = y2;
			y2 = y1;
			y1 = y4;
		}
		t = y1 + y2 + y3 +y4;
		printf("%d\n", t);
	}
}
		
			 
