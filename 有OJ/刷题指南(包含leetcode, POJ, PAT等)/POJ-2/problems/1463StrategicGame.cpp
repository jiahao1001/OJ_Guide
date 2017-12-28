#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
const int N = 1500;
int n;
vector<int> g[N];
int dp[N][2];
void dfs(int u,int f){
    int kid = 0;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==f) continue;
        dfs(v,u);
        kid ++;
        
    }
    if(!kid) dp[u][1]=1, dp[u][0] = 0;
    else{
        dp[u][0] = 0;
        for(int i=0;i<g[u].size();i++){
            int v = g[u][i];
            if(v==f)continue;
            dp[u][0] += dp[v][1];
        }
        dp[u][1] = 1;
        for(int i=0;i<g[u].size();i++){
            int v = g[u][i];
            if(v==f) continue;
            dp[u][1] += min(dp[v][1],dp[v][0]);
        }
    }
}
int main()
{
    int u,v,cnt;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) g[i].clear();
        for(int i=0;i<n;i++){
            //g[i].clear();
            scanf("%d:(%d)",&u,&cnt);
            for(int j=0;j<cnt;j++)
                scanf("%d",&v), g[u].push_back(v),g[v].push_back(u);
        }
        dfs(0,-1);
        printf("%d\n",min(dp[0][0],dp[0][1]));
    }
    return 0;
}
