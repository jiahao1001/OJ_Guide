#include <cstdio>
#include <cstring>

int main(){
	freopen("2044.in", "r", stdin);
	freopen("2044.out", "w", stdout);
	int n, i, a, b;
	scanf("%d", &n);
	long long s[50];
	s[1] = 1;
	s[2] = 2;
	for(i = 3; i < 50; i++) {
		s[i] = s[i-1] + s[i-2];
	}
	while(n--) {
		scanf("%d%d", &a, &b);
		printf("%I64d\n", s[b -a]);
	}
}
