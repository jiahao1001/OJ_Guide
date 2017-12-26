#include <stdio.h>

void print(int n){
    if(n==0)return;
    if(n==1){
        printf("%c",'A');
        return;
    }
    print(n-1);
    printf("%c",n+'A'-1);
    print(n-1);

}

int main(){
    int n;
    scanf("%d",&n);
    print(n);
    return 0;
}