#include <cstdio>

int main(){
	freopen("2038.in", "r", stdin);
	freopen("2038.out", "w", stdout);
	int n;
	float a, b, c;
	scanf("%d", &n);
	while(n > 0) {
		scanf("%f%f%f", &a, &b, &c);
		if(a+b>c&&a+c>b&&b+c>a) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		n--;
	}
}
		 
