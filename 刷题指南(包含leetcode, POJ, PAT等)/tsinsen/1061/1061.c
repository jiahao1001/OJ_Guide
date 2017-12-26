#include <stdio.h>

int main(){
    int n,i,c;
    scanf("%d",&n);
    for(i=1,c=0;i<=n;i++){
        if(n%i==0)c++;
    }
    printf("%d",c);

    return 0;
}