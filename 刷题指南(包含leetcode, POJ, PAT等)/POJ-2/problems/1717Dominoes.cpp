#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1010;
int domino[N][2];
int tot,top;
int n;
int dp[2][6*N];
int main()
{
    tot = top = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&domino[i][0],&domino[i][1]), tot += domino[i][0] + domino[i][1],top+=domino[i][0];
    memset(dp,0x3f,sizeof dp);
    dp[0][top] = 0;
    int cur = 0, nxt = 1;
    //dp i, to get this on top, min turns
    for(int i=0;i<n;i++){
        for(int j=0;j<=6*n;j++)
            if(dp[cur][j]!=inf){
                int a = domino[i][0], b = domino[i][1];
                // turn or not
                dp[nxt][j] = min(dp[cur][j],dp[nxt][j]);
                dp[nxt][j+b-a] = min(dp[cur][j]+1,dp[nxt][j+b-a]);
            }
        cur ^= 1;
        nxt ^= 1;
    }
    
    int best = inf;
    int turn = 0;
    for(int i=0;i<=6*n;i++)
        if(dp[cur][i]!=inf){
            int &x = dp[cur][i];
            if(abs(tot-i-i)<best || (abs(tot-i-i)==best && x<turn) ) best = abs(tot-i-i), turn = x;
        }
    printf("%d\n",turn);
    return 0;
}
