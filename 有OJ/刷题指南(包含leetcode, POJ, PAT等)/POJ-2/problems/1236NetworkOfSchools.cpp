#include<iostream>
#include<stdio.h>
#define N 100
using namespace std;
int n;
int g[N][N];
int scnt,cnt;
int scc[N];
int dfn[N],low[N];
int top,S[N];
void dfs(int u)
{
    dfn[u]=low[u]=cnt++;
    S[top++]=u;
    for(int i=0;i<n;i++)
        if(g[u][i]){
            if(dfn[i]==-1) dfs(i),low[u]=min(low[u],low[i]);
            else low[u]=min(low[u],dfn[i]);
        }
    int v;
    if(low[u]==dfn[u]){
        do{
            v=S[--top];
            dfn[v]=n,scc[v]=scnt;
        }while(v!=u);
        scnt++;
    }
}
int in[100],out[100];
int main()
{
    int v;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        while(scanf("%d",&v),v) g[i][v-1]=1;
    }
    memset(low,-1,sizeof(low));
    memset(dfn,-1,sizeof(dfn));
    int total=0;
    for(int i=0;i<n;i++)
        if(dfn[i]==-1) dfs(i);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(g[i][j] && scc[i]!=scc[j]) out[scc[i]]++,in[scc[j]]++;
    if(scnt==1) printf("1\n0\n");
    else
    {
        int a=0,b=0;
        for(int i=0;i<scnt;i++){
            if(in[i]==0) a++;
            if(out[i]==0) b++;
        }
        printf("%d\n",a);
        printf("%d\n",max(a,b));
    }
    
    return 0;
}
