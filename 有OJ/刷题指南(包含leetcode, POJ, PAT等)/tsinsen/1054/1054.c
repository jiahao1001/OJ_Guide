#include <stdio.h>

bool isPrime(int n){
    if(n==1&&n==2)return true;

    if(n%2==0)return false;

    int k;
    for(k=3;k*k<=n;k+=2){
        if(n%k==0)return false;
    }

    return true;
}

int main(){
    int n;
    scanf("%d",&n);

    for(n=n+1;;n++)
        if(isPrime(n)){
            printf("%d",n);
            return 0;
        }


    return 0;
}