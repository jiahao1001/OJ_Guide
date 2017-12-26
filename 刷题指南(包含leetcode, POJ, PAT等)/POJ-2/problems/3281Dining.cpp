#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int g[402][402];
int N,F,D;
int f,d,x;
int vis[402];
int dfs(int g[][402],int u,int t,int n)
{
    vis[u]=1;
    if(u==t) return 1;
    for(int i=0;i<n;i++)
        if(!vis[i]&&g[u][i])
        {
            if(dfs(g,i,t,n)){
                g[u][i]=0,g[i][u]=1;
                return 1;
            }
        }
    return 0;
}
int maxflow(int g[][402],int s,int t,int n)
{
    int f=0;
    while(dfs(g,s,t,n)) f++,memset(vis,0,sizeof(vis));
    return f;
}
int main()
{
    scanf("%d%d%d",&N,&F,&D);
    //souce 0, sink F+2N+D+1
    //F+1 -- F+N+1
    for(int i=1;i<=F;i++) g[0][i]=1;
    for(int i=F+2*N+1;i<=F+2*N+D;i++) g[i][F+2*N+D+1]=1;
    for(int i=1;i<=N;i++) g[F+i][F+N+i]=1;
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&f,&d);
        for(int j=0;j<f;j++)
            scanf("%d",&x),g[x][F+i]=1;
        for(int j=0;j<d;j++)
            scanf("%d",&x), g[F+N+i][F+2*N+x]=1;
        
    }
    printf("%d\n",maxflow(g,0,F+2*N+D+1,F+2*N+D+2));
    
    return 0;
}
