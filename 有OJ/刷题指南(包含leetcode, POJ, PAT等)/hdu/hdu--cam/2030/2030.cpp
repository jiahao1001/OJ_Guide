#include <cstdio>
#include <cstring> 
using namespace std;

int main(){
	freopen("2030.in", "r", stdin);
	freopen("2030.out", "w", stdout);
	int n;
	scanf("%d",&n);
	getchar();
	while(n--) {
		char e;
		int num = 0;
		while ((e = getchar()) != '\n') {
			if (e < 0) num++;
		}
		printf("%d\n", num / 2);
	}
}

		
