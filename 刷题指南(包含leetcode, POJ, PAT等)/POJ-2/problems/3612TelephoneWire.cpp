#include<iostream>
#include<stdio.h>
#include<string.h>
#include<limits.h>
using namespace std;
int dp[2][101];//min i pole with height of j
int low[2][101],high[2][101];
int h[100001];
int N,C;
int main()
{
    while(scanf("%d%d",&N,&C)!=EOF){
        for(int i=1;i<=N;i++)
            scanf("%d",h+i);
        
        for(int i=1;i<=100;i++)
            dp[0][i]=0;
        low[0][1]=dp[0][1]-C;
        for(int i=2;i<=100;i++)
            low[0][i]=min(dp[0][i]-C*i,low[0][i-1]);
        high[0][100]=dp[0][100]+C*100;
        for(int i=99;i>=1;i--)
            high[0][i]=min(dp[0][i]+C*i,high[0][i+1]);
        
        int prev = 0, cur=1;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=100;j++)
                dp[cur][j]=INT_MAX/2;
            for(int j=h[i];j<=100;j++)
                dp[cur][j]=(j-h[i])*(j-h[i])+min(-C*j+high[prev][j],C*j+low[prev][j]);
            
            low[cur][1]=dp[cur][1]-C;
            for(int j=2;j<=100;j++)
                low[cur][j]=min(dp[cur][j]-C*j,low[cur][j-1]);
            high[cur][100]=dp[cur][100]+C*100;
            for(int j=99;j>=1;j--)
                high[cur][j]=min(dp[cur][j]+C*j,high[cur][j+1]);
            prev ^= 1;
            cur ^= 1;
            
        }
        int answer = INT_MAX;
        for(int i=1;i<=100;i++)
            answer = min(answer,dp[prev][i]);
        printf("%d\n",answer);
    }
    return 0;
    
}
