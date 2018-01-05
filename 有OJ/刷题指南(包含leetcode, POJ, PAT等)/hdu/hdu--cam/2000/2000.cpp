#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	freopen("2000.in", "r", stdin);
	freopen("2000.out", "w", stdout);
	char ans[4];
	while (scanf("%s", ans) == 1) {
		for (int j = 2; j > 0; j--) {
			for (int i = 0; i < j; i++) {
				if (ans[i + 1] < ans[i]) {
					swap(ans[i], ans[i +1]);
				}
			}
			j--;
		}
		for (int i = 0; i < 3; i++) {
			printf("%c%C", ans[i], i < 2 ? ' ' : '\n');
		}
	}
} 
	

			
