#include <cstdio>

int main(){
	freopen("2042.in", "r", stdin);
	freopen("2042.out", "w", stdout);
	int n, i, m, a[31];
	a[0] = 3;
	for(i = 1; i < 31; i++) {
		a[i] = 2*a[i-1] - 2;
	} 	
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);
		printf("%d\n", a[m]);
	}
}	
