#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
const int N = 10010;
const int INF = 1<<20;

//no son or has only one black son
//otherwise must be black

int dp[N][3]; //0 white 1 black

int n;
vector<int> g[N];
void dfs(int u,int f){
    dp[u][0] = 1;
    dp[u][1] = INF;
    dp[u][2] = 0;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==f) continue;
        dfs(v,u);
        dp[u][0] += min(dp[v][2],dp[v][0]);
        dp[u][2] += dp[v][1];
    }
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==f) continue;
        dp[u][1] = min(dp[u][1],dp[u][2]-dp[v][1]+dp[v][0]);
    }
    
    //return 0;
}
int main()
{
    int u,v;
    while(scanf("%d",&n)){
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        printf("%d\n",min(dp[1][0],dp[1][1]));
        scanf("%d",&n);
        if(n==-1) break;
    }
    return 0;
}
