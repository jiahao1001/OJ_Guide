#include <cstdio>
#include <cmath> 
using namespace std;
unsigned long mul(unsigned long,unsigned long); 
int main(){
	//freopen("2028.in", "r", stdin);
	//freopen("2028.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1) {
		unsigned long a[n], i;
		scanf("%d %d", &a[0], &a[1]);
		a[1] = mul(a[0], a[1]);
		for (i = 2; i < n; i++) {
			scanf("%d", &a[i]);
			a[i] = mul(a[i - 1], a[i]);
		}
		printf("%d\n", a[n-1]);
	}

}

unsigned long mul(unsigned long a, unsigned long b) {
	unsigned long mul, m;
	mul = a * b;
	while (a != 0){
		if(a < b){
			m = a;
			a = b;
			b = m;
		}
		a = a % b;
	}
	mul = mul / b;
	return mul;
}
	
		
