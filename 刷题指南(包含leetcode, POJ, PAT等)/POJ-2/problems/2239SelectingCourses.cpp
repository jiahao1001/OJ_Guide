#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int g[300][12*7];
int t,p,q,n,m;
int vis[12*7];
int link[12*7];
int dfs(int u)
{
    for(int i=0;i<m;i++)
        if(!vis[i]&&g[u][i])
        {
            vis[i]=1;
            if(link[i]==-1||dfs(link[i])){
                link[i]=u;
                return 1;
            }
        }
    return 0;
}
int match()
{
    int mat=0;
    memset(link,-1,sizeof(link));
    for(int i=0;i<n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) mat++;
    }
    return mat;
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        m=12*7;
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            while(t--)
            {
                scanf("%d%d",&p,&q);
                p--,q--;
                g[i][p*12+q]=1;
            }
        }
        printf("%d\n",match());
    }
}
