#include <stdio.h>

void printAn(int n){
    int i;
    printf("sin(1");

    for(i=2;i<=n;i++){
        if(i%2==0)printf("-");
        else printf("+");

        printf("sin(%d",i);
    }

    for(i=0;i<n;i++)printf(")");
}


int main(){
    int n,i,j;
    scanf("%d",&n);


    for(i=0;i<n-1;i++)printf("(");

    for(i=n;i>1;i--){
        printAn(n-i+1);
        printf("+%d)",i);
    }

    printAn(n);
    printf("+1");

    return 0;
}