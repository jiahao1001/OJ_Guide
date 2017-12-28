#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
int C,N,M;
double dp[2][101];
int main()
{
    while(scanf("%d",&C),C){
        scanf("%d%d",&N,&M);
        if(M>C || M>N || ((M%2)^(N%2))) {
            printf("0.000\n");
            continue;
        }
        if(N> 1000) N =	1000 + N % 2;
        memset(dp,0,sizeof dp);
        dp[0][0] = 1;
        int cur = 1, next = 0;
        for(int i=1;i<=N;i++){
            swap(cur,next);
            for(int j=0;j<=C&&j<=i;j++){
                dp[next][j] = 0;
                if(j>0) dp[next][j] += dp[cur][j-1]*(C-j+1.0)/C;
                if(j!=C) dp[next][j] += dp[cur][j+1]*(j+1.0)/C;
            }
        }
        printf("%.3f\n",dp[next][M]);
    }
    return 0;
}
