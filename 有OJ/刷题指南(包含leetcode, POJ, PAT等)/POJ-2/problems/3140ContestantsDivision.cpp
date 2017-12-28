#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
#define abs(x) (x>0?x:-(x))
const int N = 100001;
long long w[N];
long long size[N];
int n,m;
long long diff;
long long total;
vector<int> g[N];
void dfs(int u,int f){
    size[u] = w[u];
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==f) continue;
        dfs(v,u);
        size[u] += size[v];
    }
    long long lm  = abs(total-size[u]-size[u]);
    if(lm<diff) diff  = lm;
}
int main()
{
    int q=1;
    while(scanf("%d%d",&n,&m),n||m){
        total = 0;
        for(int i=1;i<=n;i++)
            scanf("%lld",w+i),g[i].clear(),total+=w[i];
        diff = (long long)(1e16);
        int u,v;
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        printf("Case %d: %lld\n",q++,diff);
    }
    return 0;
}
