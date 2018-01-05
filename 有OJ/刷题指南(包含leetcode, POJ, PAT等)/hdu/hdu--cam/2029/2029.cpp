#include <cstdio>
#include <cstring> 
using namespace std;

int main(){
	freopen("2029.in", "r", stdin);
	freopen("2029.out", "w", stdout);
	int n, i(0), num, j;
	char s[1000];
	scanf("%d", &n);
	while(i < n) {
		scanf("%s", s);
		num = strlen(s) - 1;
		for(j = 0; j <=num; j++) {
			if(s[j] != s[num] ) {
				printf("no\n");
				break;
			}
			num--;
		}
		if(j >= num) {
			printf("yes\n");
		}
	i++;
	}
}
		
		
