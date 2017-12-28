//dp[i][s], i row state s, the number of ways.
// for i - 1 all the s, update dp[i][s]
// unreachable -1
// row 0, no plant, 1,
// dp[0][]
// row 0  is 00000 
// dp[M+1][0] is the answer row M+1 0 0 0

//dp[][] = -1
#include<iostream>
#include<stdio.h>
#define bit(s,i) (((s)>>(N-i-1))&1)
using namespace std;
int M,N;
int dp[14][1<<12];
int field[14][12];
void dfs(int i,int j,int s,int t)
{
    //row i, last config is s
    if(j==N){
        if(dp[i][t]==-1) dp[i][t]=dp[i-1][s];
        else dp[i][t]=(dp[i][t]+dp[i-1][s])%100000000;
        return;
    }
    // plant, last row not plant, left not plant, place is plantable
    if(field[i][j] && !bit(s,j) && (!j || !(t&1)))
        dfs(i,j+1,s,(t<<1)+1);
    //not plant
    dfs(i,j+1,s,t<<1);
    
}
// 000 001 100 101
// 0 1 4 5
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&M,&N);
    for(int i=1;i<=M;i++)
        for(int j=0;j<N;j++) scanf("%d",&field[i][j]);
    dp[0][0] = 1;
    for(int i=0;i<=M;i++)
        for(int s=0;s<(1<<N);s++)
            if(dp[i][s]!=-1) dfs(i+1,0,s,0);
    
    
    
    printf("%d\n",dp[M+1][0]);
}
