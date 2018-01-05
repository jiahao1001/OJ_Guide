#include <cstdio>

int main(){
	freopen("2048.in", "r", stdin);
	freopen("2048.out", "w", stdout);
	double a[21], b[21], c[21];
	int i;
	a[2] = 1;
	a[3] =2;
	b[1] =1;
	for(i = 4 ; i < 21; i++) {
		a[i] =  (i -1) *(a[i -1] + a[i -2]);
	}
	for(i =2; i < 21; i++) {
		b[i] = i *b[i -1];
	}
	for(i =2; i < 21; i++) {
		c[i] =  a[i]/b[i] * 100;
	}
	int n, m;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &m);
		printf("%.2f%%\n", c[m]);
	}
}
		
		
	
	
