#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int N = 10001;
vector<int> g[N];
int n,m;
int best = 1;
int dfn[N],low[N],cnt;
int root;
void dfs(int u,int f){
    dfn[u]=low[u] = cnt++;
    int parts = 0;
    bool ok = false;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==f)continue;
        if(dfn[v]==-1){
            dfs(v,u);
            //parts++;
            low[u] = min(low[u],low[v]);
            if(low[v]>=dfn[u]) ok = true, parts++;
        }else if(dfn[u]>dfn[v]) low[u] = min(low[u],dfn[v]);
        
    }
    if(ok){
        if(u==root) best = max(best,parts);
        else best = max(best,parts+1);
    }
    
}
int main()
{
    int u,v;
    while(scanf("%d%d",&n,&m),n||m){
        for(int i=0;i<n;i++) g[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(m==0){
            printf("%d\n",n-1);
            continue;
        }
        memset(dfn,-1,sizeof(dfn));
        memset(low,-1,sizeof(low));
        cnt = 0;
        best = 1;
        int total = 0;
        for(int i=0;i<n;i++)
            if(dfn[i]==-1){
                root = i;
                dfs(i,-1);
                total++;
            }
        printf("%d\n",total-1+best);
    }
    return 0;
}
