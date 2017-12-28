#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

char truck[2000][8];
int N;
int g[2000][2000];
int dist(char *p, char *q)
{
    int t=0;
    int len=strlen(p);
    for(int i=0;i<len;i++)
        t+=(p[i]==q[i]?0:1);
    return t;
}
int d[2000];
int vis[2000];
int mst()
{
    memset(vis,0,sizeof(vis));
    memset(d,0x3f,sizeof(d));
    int total=0;
    vis[0]=1;
    d[0]=0;
    for(int i=0;i<N;i++)
        if(!vis[i]) d[i]=min(d[i],g[0][i]);
    for(int i=1;i<N;i++)
    {
        int dmax=0x3f3f3f3f;
        int jj;
        for(int j=0;j<N;j++)
            if(!vis[j] && d[j]<dmax) dmax=d[j],jj=j;
        vis[jj]=1;
        total+=d[jj];
        for(int j=0;j<N;j++)
            if(!vis[j]) d[j]=min(d[j],g[jj][j]);
    }
    
    return total;
}
int main()
{
    while(scanf("%d",&N),N)
    {
        for(int i=0;i<N;i++)
            scanf("%s",truck[i]);
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                g[i][j]=dist(truck[i],truck[j]);
        printf("The highest possible quality is 1/%d.\n",mst());
    }
    return 0;
}
