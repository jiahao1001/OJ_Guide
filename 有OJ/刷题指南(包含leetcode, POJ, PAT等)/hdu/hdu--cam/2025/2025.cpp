#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    //freopen("2025.in", "r", stdin);
    //freopen("2025.out", "w", stdout);
    int num, i;
    char s[1000], max;
    while (scanf("%s", s) != EOF) {
          num = strlen(s);
          max = s[0];
          for (i = 1; i < num; i++) {
              if(max < s[i]) {
                     max = s[i];
              }
          }
          for (i = 0 ; i < num; i++) {
              printf("%c", s[i]);
              if (max == s[i]) {
                      printf("(max)");
              }
          }
          printf("\n");
    }
} 
          
          
