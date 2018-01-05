
#include <cstdio>

int main() {
	freopen("2036.in", "r", stdin);
	freopen("2036.out", "w", stdout);
	int n, y1, y2, y3, x1, x2, x3;
	int x[101], y[101];
	double t;
	while(~scanf("%d", &n)) {
		int i;
		t = 0;
		if(n == 0) break;
		scanf("%d%d", &x1, &y1);
		for(i = 1;i < n; i++) {
			scanf("%d%d", &x[i], &y[i]);
		}
		for(i = 1; i < (n-1); i++) {
			x2 = x[i];
			y2 = y[i];
			x3 = x[i+1];
			y3 = y[i+1];
			t +=(double)(x2*y3+x1*y2+x3*y1-x3*y2-x2*y1-x1*y3)/2.0;
		}
		printf("%.1f\n", t);
	}
}
			 
