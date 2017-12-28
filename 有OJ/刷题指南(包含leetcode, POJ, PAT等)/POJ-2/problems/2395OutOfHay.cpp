#include<iostream>
#include<stdio.h>
using namespace std;
int g[2000][2000];
int d[2000];
int vis[2000];
int n,M;
int main()
{
    scanf("%d%d",&n,&M);
    int u,v,w;
    memset(g,0x7f,sizeof(g));
    memset(d,0x7f,sizeof(d));
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        u--,v--;
        g[u][v]=min(g[u][v],w);
        g[v][u]=min(g[v][u],w);
    }
    //prim
    int bottle=0;
    d[0]=0;
    for(int i=0;i<n;i++)
    {
        int jj,best=0x7f7f7f7f;
        for(int j=0;j<n;j++)
            if(!vis[j]&&d[j]<best) best=d[j],jj=j;
        vis[jj]=1;
        bottle=max(bottle,best);
        for(int j=0;j<n;j++)
            if(!vis[j]&&g[jj][j]<d[j]) d[j]=g[jj][j];
    }
    
    
    printf("%d\n",bottle);
    return 0;
    
}
