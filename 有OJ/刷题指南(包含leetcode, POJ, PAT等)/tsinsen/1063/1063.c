#include <stdio.h>
#include <math.h>

long long v;
int main(){
    int n,i,x,a,j;
    scanf("%d",&n);
    scanf("%d",&x);
    v=0;
    scanf("%d",&a);  //jump 0
    for(i=0;i<n;i++){
        scanf("%d",&a);
        int tmp=1;
        for(j=0;j<i;j++)tmp=(tmp*x)%9999;
        v=(v+(a*tmp)%9999*(i+1))%9999;  //(a + b) % n = (a % n + b % n) % n 
    }

    printf("%d",(v+9999)%9999);
    return 0;
}