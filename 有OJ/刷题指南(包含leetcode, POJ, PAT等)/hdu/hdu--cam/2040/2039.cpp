#include <cstdio>

int main(){
	freopen("2039.in", "r", stdin);
	freopen("2039.out", "w", stdout);
	int n, a, b;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &a, &b);
		int i, t(0), g(0);
		for(i = 1; i < a; i++){
			if((a%i) == 0)
			t += i;
		}
		if(t != b) {
			printf("NO\n");
			continue;
		}
		for(i = 1; i < b; i++) {
			if((b%i) == 0)
			g += i;
		}
		if(g == a) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
