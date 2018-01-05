#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    freopen("2022.in", "r", stdin);
    freopen("2022.out", "w", stdout);
    int m, n;
    while (scanf("%d%d", &m, &n) == 2) {
          int g = m * n;
          if(!g) break;
          int ans[g], j = 0, max;
          scanf("%d", &ans[0]);
          max = ans[0];
          for (int i = 1; i < g; i++) {
              scanf("%d", &ans[i]);
              if (abs(max) < abs(ans[i])){
                           max = ans[i];
                           j = i;
              }
          }
          int m1, n1;
          j = j + 1;
          m1 = j / n + 1;
          n1 = j % n;
          if (!n1) {
          n1 = n; 
          m1 = m1 - 1;
          }
          printf ("%d %d %d\n", m1, n1, ans[j - 1]);
    }
}
          
    
          
                            
          
                        
                                    
    

                      
