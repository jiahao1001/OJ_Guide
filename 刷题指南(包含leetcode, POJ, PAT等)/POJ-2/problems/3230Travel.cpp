#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
int dp[120][120];
int N,M;
int cost[120][120], income[120][120];
int main()
{
    while(scanf("%d%d",&N,&M),N||M){
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++) scanf("%d",&cost[i][j]);
        for(int i=1;i<=M;i++)
            for(int j=1;j<=N;j++) scanf("%d",&income[i][j]);
        for(int i=0;i<=M;i++)
            for(int j=0;j<=N;j++) dp[i][j] = INT_MIN;
        dp[0][1] = 0;
        for(int i=0;i<M;i++){
            //day i, city j
            for(int j=1;j<=N;j++)
                if(dp[i][j]!=INT_MIN){
                    for(int k=1;k<=N;k++)
                        dp[i+1][k] = max(dp[i+1][k], dp[i][j]-cost[j][k]+income[i+1][k]);
                }
                    
        }
        int best = INT_MIN;
        for(int i=1;i<=N;i++) best = max(best,dp[M][i]);
        printf("%d\n",best);
    }
    return 0;
}
