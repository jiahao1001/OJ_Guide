#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    freopen("2026.in", "r", stdin);
    freopen("2026.out", "w", stdout);
    char s[1000], f;
    int num, i, flag(0);
    while (gets(s)) {
          num = strlen(s);
          f = s[0] - 32;
          printf("%c", s[0]);
          for (i = 1; i < num; i++) {
        	if(flag == 1) {
                       f = s[i] - 32;
                       flag = 0;
                       printf("%c", )
			}
			if (s[i] == '') {
				flag = 1;
			}
			printf("%c", f);
		}
	}
} 
				
