#include <stdio.h>

int main(){
    int a,b,m,i,j;

    scanf("%d,%d,%d",&a,&b,&m);

    for(i=1;a*i+b<=m;i++){
        for(j=i;a*i+b*j<=m;j++){
            printf("%d,%d\n",i,j);
        }
    }

    return 0;
}