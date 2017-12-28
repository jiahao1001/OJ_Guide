#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 31;
int dp[N][N][N];
int g[N][N];
int n;
int f(int i,int j,int k){
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(k==n-1) return dp[i][j][k] = 0;
    dp[i][j][k] = INT_MAX;
    
    dp[i][j][k] = min(dp[i][j][k],f(i,j,k+1)+g[k][k+1]);
    dp[i][j][k] = min(dp[i][j][k],f(i,k,k+1)+g[j][k+1]);
    dp[i][j][k] = min(dp[i][j][k],f(j,k,k+1)+g[i][k+1]);
    return dp[i][j][k];
    
}
int main()
{
    int m;
    scanf("%d",&m);
    while(m--){
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                scanf("%d",&g[i][j]);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",f(0,0,0));
    }
    return 0;
}
