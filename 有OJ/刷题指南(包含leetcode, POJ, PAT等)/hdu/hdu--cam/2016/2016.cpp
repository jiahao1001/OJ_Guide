#include <cstdio>
using namespace std;

int main(){
	freopen("2016.in", "r", stdin);
	freopen("2016.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1) {
		if (n == 0) break;
		int i = 1, ans[100], min, j(0);
		scanf("%d", &ans[0]);
		min = ans[0];
		while (i < n) {
			scanf("%d", &ans[i]);
			if(ans[i] < min) {
				min = ans[i];
				j = i;
			}
				i++;
		}
		ans[j] = ans[0];
		ans[0] = min;
		for (i = 0; i < n; i++) {
			if(i == 0) { 
				printf("%d", ans[i]);
			} else {
				printf(" %d", ans[i]);
			}
		}
		printf("\n");
	}
}	
			
			
