#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<limits.h>
using namespace std;
const int N = 1024;
const int M = 2048;
int key[N][2], door[M][2];
vector<int> g[4*N];
int n,m;
int s_cnt, cnt, dfn[4*N], low[4*N],scc[4*N];
stack<int> S;
void dfs(int u){
    dfn[u] = low[u] = cnt++;
    S.push(u);
    for(int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        if(dfn[v]==-1){
            dfs(v);
            low[u] = min(low[u],low[v]);
        }else low[u] = min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        int v;
        int id = s_cnt++;
        do{
            v = S.top();
            S.pop();
            dfn[v] = 4*n;
            scc[v] = id;
        }while(v!=u);
    }
    
}
inline bool check(int x){
    //open first x doors
    int a,b;
    for(int i=0;i<4*n;i++) g[i].clear();
    for(int i=0;i<n;i++){
        a = key[i][0], b = key[i][1];
        g[2*a].push_back(2*b+1);
        g[2*b].push_back(2*a+1);
        //g[2*a][2*b+1] = 1;
        //g[2*b][2*a+1] = 1;
    }
    for(int i=0;i<x;i++){
        a = door[i][0], b = door[i][1];
        g[2*a+1].push_back(2*b);
        g[2*b+1].push_back(2*a);
        //g[2*a+1][2*b] = 1;
        //g[2*b+1][2*a] = 1;
    }
    //tarjan and check
    memset(dfn,-1,sizeof dfn);
    memset(low,-1,sizeof low);
    memset(scc,-1,sizeof scc);
    cnt = s_cnt = 0;
    for(int i=0;i<4*n;i++)
        if(dfn[i]==-1) dfs(i);
    for(int i=0;i<2*n;i++)
        if(scc[2*i]==scc[2*i+1]) return false;
    return true;
    
}

int main()
{
    while(scanf("%d%d",&n,&m),n||m){
        for(int i=0;i<n;i++) scanf("%d%d",&key[i][0],&key[i][1]);
        for(int i=0;i<m;i++) scanf("%d%d",&door[i][0],&door[i][1]);
        //key  i->!j, j->!i      door !i->j   !j->i
        if(check(m)){
            printf("%d\n",m);
            continue;
        }
        int l = 0, r = m;
        int mid;
        while(l+1<r){
            mid = (l+r)>>1;
            if(check(mid)) l = mid;
            else r = mid;
        }
        printf("%d\n",l);
    }
    return 0;
}
