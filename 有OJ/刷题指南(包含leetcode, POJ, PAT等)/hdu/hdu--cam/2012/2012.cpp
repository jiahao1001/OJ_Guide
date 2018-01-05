#include <cstdio>
#include <cmath>
using namespace std;

int Isprime(int);
int main(){
	//freopen("2012.in", "r", stdin);
	//freopen("2012.out", "w", stdout);
	int x, y;
	while (scanf("%d %d", &x, &y) == 2) {
		if (x ==0 && y ==0) break;
		int i = x, ans, j(0);
		for (; i <= y; i++) {
			ans = i * i + i + 41;
			if (Isprime(ans)) {
				j++;
			}
		}
		if (j > 0) {
			printf("Sorry\n");
		} else {
			printf("OK\n");
		}
	}
}

int Isprime(int ans){
	int  result, ctr = 2;
	while (ctr < ans) {
		result = ans % ctr;
		if (result == 0) {
			return 1;
		}
		ctr++;
	}
	return 0;
}  
			
			
			
			
		
