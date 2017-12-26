#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
const int inf = 1000000;
const int N = 100000;
vector<int> g[N];
bool trap[N];
int n,m;
int dp[N][3]; //0 traverse all, 1, have a subtree missing, 2 not at all

void dfs(int u,int f){
    dp[u][0] = dp[u][1] = dp[u][2] = inf;
    if(trap[u]){
        dp[u][0] = dp[u][1] = inf, dp[u][2] = 0;
        return;
    }
    if(u!=1 && g[u].size()==1){
        dp[u][0] = 0;
        dp[u][1] = inf;
        dp[u][2] = 1;
        return ;
    }
    int l=-1,r=-1;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==f)continue;
        dfs(v,u);
        if(l==-1) l =v;
        else r=v;
    }
    if(r==-1) dp[u][0]=dp[l][0],dp[u][1] = dp[l][1],dp[u][2]=dp[l][2];
    else{
        
        dp[u][0]=dp[l][0]+dp[r][0];
        dp[u][1]=min(dp[u][1],dp[l][0]+dp[r][2]);
        dp[u][1]=min(dp[u][1],dp[r][0]+dp[l][2]);
        dp[u][1]=min(dp[u][1],dp[l][0]+dp[r][1]);
        dp[u][1]=min(dp[u][1],dp[r][0]+dp[l][1]);
        dp[u][2]=dp[u][1]+1;
        dp[u][2]=min(dp[u][2],dp[l][2]+dp[r][2]);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)){
        if(!n && !m) break;
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++)
            g[i].clear(), trap[i] = false;
        for(int i=1;i<=n;i++){
            int cnt,x;
            scanf("%d",&cnt);
            for(int j=1;j<=cnt;j++){
                scanf("%d",&x);
                g[i].push_back(x);
            }
        }
        for(int i=1;i<=m;i++){
            int u;
            scanf("%d",&u);
            trap[u] = 1;
        }
        dfs(1,1);
        printf("%d\n",dp[1][2]);
        
    }
    return 0;
}
