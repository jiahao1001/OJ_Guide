#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 10001;
vector<int> g[N];
int n;
int marble[N];
int total;
void dfs(int u,int f){
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(v==f) continue;
        dfs(v,u);
        if(marble[v]>=1) marble[u]+=marble[v]-1, total+=marble[v]-1;
        else marble[u]-=(1-marble[v]), total+=(1-marble[v]);
    }
}
int main()
{
    int cnt,u,v;
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&u,marble+i,&cnt);
            for(int j=0;j<cnt;j++)
                scanf("%d",&v),g[u].push_back(v), g[v].push_back(u);
        }
        total = 0;
        dfs(1,0);
        printf("%d\n",total);
        
    }
    return 0;
}
