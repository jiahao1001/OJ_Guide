#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
int dp[10001][501];
int N,M,D[10001];
int A[10001];
int main()
{
    scanf("%d%d",&N,&M);
    A[0] = 0;
    for(int i=1;i<=N;i++)
        scanf("%d",D+i), A[i] = A[i-1]+D[i];
    //dp(i,j) time i, ex j
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    for(int i=0;i<N;i++){
        if(dp[i][0]!=-1)
            for(int j=1;j<=M && i+j<=N;j++)
            dp[i+j][j] = max(dp[i+j][j],dp[i][0]+A[i+j]-A[i]);
        for(int j=1;j<=M;j++){
            dp[i+1][0] = max(dp[i+1][0],dp[i][0]);
            if(dp[i][j]!=-1) dp[i+1][j-1] = max(dp[i+1][j-1],dp[i][j]);
        }
    }
    printf("%d\n",dp[N][0]);
    return 0;
}
