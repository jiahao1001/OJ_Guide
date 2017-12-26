#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
int dp[11][101][101];
int f(int k,int s,int e){
    if(dp[k][s][e]) return dp[k][s][e];
    if(s==e) return dp[k][s][e] = s;
    if(k==1) return dp[k][s][e] = (s+e)*(e-s+1)/2;
    int m1,m2,m,v = INT_MAX/2;
    for(int t=s;t<=e;t++){
        if(t==s) m1 = 0;
        else
            m1 = f(k-1,s,t-1);
        if(t==e) m2 = 0;
        else
        m2 = f(k,t+1,e);
        m = max(m1,m2);
        v = min(v,m+t);
    }
    return dp[k][s][e] = v;
}
int main(){
    int t,k,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&k,&n);
        memset(dp,0,sizeof(dp));
        printf("%d\n",f(k,1,n));
    }
    return 0;
}
