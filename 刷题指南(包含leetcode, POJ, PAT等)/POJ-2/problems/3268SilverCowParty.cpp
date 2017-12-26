#include<iostream>
#include<stdio.h>
#include<string.h>
#define N 1000
#define inf 0x3f3f3f3f
using namespace std;
int d1[N],vis[N];
int d2[N];
int g1[N][N];
int g2[N][N];
int n,m,x;
int u,v,w;
void dijkstra(int g[][N],int d[])
{
    memset(d,0x3f,sizeof(int)*N);
    memset(vis,0,sizeof(vis));
    d[x]=0;
    for(int i=0;i<n;i++)
    {
        int best=inf,jj;
        for(int j=0;j<n;j++)
            if(!vis[j] && d[j]<best) best=d[j],jj=j;
        vis[jj]=1;
        for(int j=0;j<n;j++)
            if(!vis[j] && d[jj]+g[jj][j]<d[j]) d[j]=d[jj]+g[jj][j];
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&x);
    x--;
    memset(g1,0x3f,sizeof(g1));
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        u--,v--;
        g1[u][v]=w;
    }
    int best=0;
    dijkstra(g1,d1);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g2[i][j]=g1[j][i];
    dijkstra(g2,d2);
    
    for(int i=0;i<n;i++)
        best=max(best,d1[i]+d2[i]);
    printf("%d\n",best);
    return 0;
}
