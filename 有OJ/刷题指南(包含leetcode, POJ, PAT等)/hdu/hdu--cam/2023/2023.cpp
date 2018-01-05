#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    //freopen("2023.in", "r", stdin);
    //freopen("2023.out", "w", stdout);
    int m, n;
    while (scanf("%d %d",  &n, &m) == 2) {
          double a[n][m], ave[n];
          int i, j;
          for(i = 0; i < n; i++) {
                ave[i] = 0;
                for(j = 0; j < m; j++) {
                      scanf("%lf", &a[i][j]);
                      ave[i] += a[i][j];
                }
                ave[i] = ave[i] / m;
                if(!i) { 
                       printf("%.2f", ave[i]);
                       } else {
                              printf(" %.2f", ave[i]);
                              }
          }
          printf("\n");
          double ke[m];
          for (i = 0; i < m; i++) {
              ke[i] = 0;
              for(j = 0; j < n; j++) {
                    ke[i] += a[j][i];
              }
              ke[i] = ke[i] / n;
              if(!i) { 
                       printf("%.2f", ke[i]);
                       } else {
                              printf(" %.2f", ke[i]);
                              }
          }
          printf("\n");
          int num(0), p(0);
          for (i = 0; i < n; i++) {
              p = 0;
              for (j = 0; j < m; j++) {
                  if(a[i][j] < ke[j]) {
                             p = 1;
                             break;
                  }
              }
              if(!p) num++;
          }
          printf("%d\n\n", num);
    }
}
          
                       
                            
                
                      
