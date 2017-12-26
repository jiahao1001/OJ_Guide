#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==0) {
        printf("0\n");
        return 0;
    }
    int bit[50],cnt=0;
    int sign = 1;
    if(n<0) n=-n, sign = -1;
    while(n){
        int a = 0;
        if(n&1){
            bit[cnt++]=1;
            if(sign<0) a = 1;
        }else bit[cnt++]=0;
        sign = -sign;
        n/=2, n+=a;
    }
    for(int i=cnt-1;i>=0;i--) printf("%d",bit[i]);
    printf("\n");
}
