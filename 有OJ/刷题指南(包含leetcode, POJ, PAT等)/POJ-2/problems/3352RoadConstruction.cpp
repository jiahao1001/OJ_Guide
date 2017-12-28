#include <iostream>
#include <vector>
#include <string.h>
#include <utility>
#include <stack>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
int n,r;
vector<int> g[N];
vector<PII> bridges;
int bcc[N];
int b_cnt;
int num;
int dfn[N],low[N];
int degree[N];
void dfs(int u,int f){
    dfn[u] = low[u] = num++;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==f) continue;
        if(dfn[v]==0){
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>dfn[u]) bridges.push_back(make_pair(u,v));
            //son
        }else if(dfn[v]<dfn[u]){
            //frond
            low[u] = min(low[u],dfn[v]);
        }
    }
    
}
void dfs1(int u,int b){
    bcc[u] = b;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(bcc[v]==-1) dfs1(v,b);
    }
}

int main(){
    scanf("%d%d",&n,&r);
    int u,v;
    for(int i=0;i<r;i++){
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    b_cnt = 0;
    num = 1;
    memset(bcc,-1,sizeof(bcc));
    dfs(1,0);
    for(int i=0;i<bridges.size();i++){
        u = bridges[i].first;
        v = bridges[i].second;
        g[u].erase(find(g[u].begin(),g[u].end(),v));
        g[v].erase(find(g[v].begin(),g[v].end(),u));
    }
    for(int i=1;i<=n;i++){
        if(bcc[i]==-1) dfs1(i,b_cnt++);
    }
    for(int i=0;i<bridges.size();i++){
        u = bridges[i].first;
        v = bridges[i].second;
        degree[bcc[u]] ++;
        degree[bcc[v]] ++;
    }
    
    
    int res = 0;
    for(int i=0;i<b_cnt;i++)
        if(degree[i]==1) res++;
    printf("%d\n",(res+1)/2);
    
    return 0;
    
}
