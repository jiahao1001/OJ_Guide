#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    //freopen("2024.in", "r", stdin);
    //freopen("2024.out", "w", stdout);
    int n;
    char s[1000];
    int i, flag, num, k;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        flag = 0;
        gets(s);
        num = strlen(s);
        for (k = 0; k < num; k++) {
            if (!((s[k] >= '0'&& s[k] <= '9') || (s[k] >= 'a'&& s[k] <= 'z') || (s[k] >= 'A'&& s[k] <= 'Z') || (s[k] == '_'))) {
               flag = 1;
            }
        }
        if (s[0] >= '0'&&s[0] <= '9') {
           flag = 1;
        }
        if(flag){
                 printf("no\n");
                 } else {
                        printf("yes\n");
                        }
    }
} 
