#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
#define MAXN 110
vector<int> g[MAXN];
int vis[MAXN];
int n,e;
int dfs(int u,int f)
{
    vis[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==f) continue;
        if(vis[v]) return -1;
        if(dfs(v,u)==-1) return -1;
    }
    return 0;
}
bool caterpillar_dfs(int u,int f)
{
    vis[u]=1;
    
    // exit
    if(g[u].size()==1 && f)
    {
//        cout<<"reach"<<u<<endl;
        for(int i=1;i<=n;i++)
            if(!vis[i]) {
                vis[u]=2;
                return false;
            }
        return true;
    }
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=f) vis[v]=2; //neighbor is visited.
    }
    //dfs
    
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==f) continue;
        if(caterpillar_dfs(v,u)) return true;
    }
    
    //backtrack
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=f && vis[v]==2) vis[v]=0;
    }
    vis[u]=2;
    return false;
}
bool caterpillar()
{
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(caterpillar_dfs(i,0)) return true;
    }
    return false;
}
int main()
{
    int q=1;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&e);
        if(n==1 && e==0) goto success;
        for(int i=1;i<=n;i++)
            g[i].clear();
        int a,b;
        for(int i=0;i<e;i++)
        {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(vis,0,sizeof(vis));
        if(dfs(1,0)==-1) goto fail;
        for(int i=1;i<=n;i++)
            if(!vis[i]) goto fail;
        
        if(caterpillar()){
        success:    printf("Graph %d is a caterpillar.\n",q++);
            continue;
        }
    fail:
        printf("Graph %d is not a caterpillar.\n",q++);
        
    }
}
