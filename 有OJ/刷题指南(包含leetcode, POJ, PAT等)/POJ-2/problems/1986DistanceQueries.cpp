#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
#define MAXN 40000

vector<int> adj[MAXN];
vector<int> query[MAXN];
vector<int> id[MAXN];
vector<int> w[MAXN];
int answer[10000];
int N,M,K;
char dir;
int u,v,len;
int parent[MAXN];
int vis[MAXN];
int d[MAXN];
inline void make_set(int u)
{
    parent[u]=u;
}
inline int find_set(int u)
{
    if(parent[u]==u) return u;
    int r=find_set(parent[u]);
    parent[u]=r;
    return r;
    
}
void dfs(int u,int f,int dis)
{
    make_set(u);
    d[u]=dis;
    int v;
    for(int i=0;i<adj[u].size();i++)
    {
        v=adj[u][i];
        if(v!=f && !vis[v]) dfs(v,u,dis+w[u][i]);
    }
    vis[u]=1;
    for(int i=0;i<query[u].size();i++)
    {
        v=query[u][i];
        if(vis[v]){
            answer[id[u][i]]=d[u]+d[v]\
                -2*d[find_set(v)];
        }
    }
    parent[u]=f;
    
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d %c",&u,&v,&len,&dir);
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        w[u].push_back(len);
        w[v].push_back(len);
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        scanf("%d%d",&u,&v);
        u--,v--;
        query[u].push_back(v);
        id[u].push_back(i);
        query[v].push_back(u);
        id[v].push_back(i);
    }
    dfs(0,-1,0);
    
    for(int i=0;i<K;i++)
        printf("%d\n",answer[i]);
    
    return 0;
}
