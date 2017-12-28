#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;
const int N = 100000;
vector<int> adj[N];
int n,m;
int p[N],deg[N];
int dp[N];
int dfs(int u){
    if(dp[u]!=INT_MIN) return dp[u];
    if(adj[u].size()==0) return dp[u] = p[u];
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        dp[u] = max(dp[u],p[u]+dfs(v));
    }
    return dp[u];
}
int main(){
    while(scanf("%d%d",&n,&m)!=-1){
        for(int i=0;i<n;i++){
            scanf("%d",p+i);
            adj[i].clear();
            deg[i] = 0;
            dp[i] = INT_MIN;
        }
        int x,y;
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            x--,y--;
            adj[x].push_back(y);
            deg[y] ++;
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
            if(!deg[i]) ans = max(ans,dfs(i));
        printf("%d\n",ans);
        
    }
    return 0;
}
