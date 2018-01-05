#include <cstdio>
#include <cstring>

int main(){
	//freopen("2017.in", "r", stdin);
	//freopen("2017.out", "w", stdout);
	int n;
	scanf("%d", &n);
	char stl[1000];
	int i, j, num, k;
	for (i = 0; i < n; i++) {
		j = 0;
		scanf("%s", stl);
		num = strlen(stl);
		for (k = 0; k < num; k++) {
			if (stl[k] >= '0' && stl[k] <= '9') {
				j++;
			}
		}
		printf("%d\n", j);
	}
}
		
	
	
