#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int gcd(int x,int y){
    if(!y) return x;
    return gcd(y,x%y);
}
int main()
{
    while(scanf("%d",&n),n){
        int x;
        int m = 1;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            m = m/gcd(m,x)*x;
        }
        if(m>=1000000)printf("Too much money to pay!\n");
        else printf("The CEO must bring %d pounds.\n",m);
    }
    return 0;
}
