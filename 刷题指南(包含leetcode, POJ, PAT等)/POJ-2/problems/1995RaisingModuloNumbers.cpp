#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
int M,H;
int raising(int A,int B){
    A%=M;
    int r = 1;
    int u = A;
    while(B){
        if(B&1) r = (r*u)%M;
        B>>=1;
        u=(u*u)%M;
    }
    return r;
}
int main()
{
    int t;
    int A,B;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&M);
        scanf("%d",&H);
        int ans = 0;
        while(H--){
            scanf("%d%d",&A,&B);
            ans = (ans+raising(A,B))%M;
        }
        printf("%d\n",ans);
    }
    return 0;
}
