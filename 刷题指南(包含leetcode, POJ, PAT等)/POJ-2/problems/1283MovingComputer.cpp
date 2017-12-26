#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int n,K;
long long dp[2][201][201];//i truck total j, i truck has k
long long sum[201][201];
int main()
{
    while(scanf("%d%d",&n,&K),n||K){
        memset(dp,0,sizeof dp);
        int cur = 0, nt = 1;
        for(int i=1;i<=n;i++)
            dp[cur][i][i] = 1;
        for(int i=2;i<=K;i++){
            memset(sum,0,sizeof sum);
            for(int j=1;j<n;j++)
                for(int k=1;k<=n;k++)
                    sum[j][k] = sum[j][k-1]+dp[cur][j][k];
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++){
                    dp[nt][j][k] = 0;
                    if(j-k<1) continue;
                    dp[nt][j][k] = sum[j-k][k];
                }
            cur^=1, nt^=1;
        }
        long long tot = 0;
        for(int i=1;i<=n;i++)
            tot+=dp[cur][n][i];
        printf("%lld\n",tot);
    }
    return 0;
}
