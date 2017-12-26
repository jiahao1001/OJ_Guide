
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

double p[130][130];
double dp[130][256];
int n;
inline int lb(int x){
    return x&(-x);
}
double dfs(unsigned int i,int x){
    if(dp[i][x]!=-1) return dp[i][x];
    int y=x;
    int cnt=0;
    while(y%2==0) cnt++, y>>=1;
    cnt = n - cnt;
    //beat 2^cnt - 1 teams
    int m = (1<<cnt) -1;
    int j = i^(i&m);
    int k = j + (1<<(cnt-1));
    int l = k + (1<<(cnt-1));
    int a,b;
    if(i>=k) a = j,b=k;
    else a=k,b=l;
    dp[i][x] = 0;
    for(int j=a;j<b;j++)
        dp[i][x] += dfs(j,x-lb(x))*p[i][j]*dfs(i,x-lb(x));
    
    return dp[i][x];
}
int main() {
    while(scanf("%d",&n),n!=-1){
        for(int i=0;i<(1<<n);i++)
            for(int j=0;j<(1<<n);j++)
                scanf("%lf",&p[i][j]);
        for(int i=0;i<130;i++)
            for(int j=0;j<256;j++) dp[i][j] = -1;
        for(int i=0;i<(1<<n);i++)
            dp[i][1<<n] = 1;
        int ans = 0;
        double best = -1;
        for(int i=0;i<(1<<n);i++){
            int x = (1<<(n+1))-1;
            //printf("%d -> %f\n",i+1,dfs(i,x));
            if(best<dfs(i,x)) best = dfs(i,x), ans = i;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
