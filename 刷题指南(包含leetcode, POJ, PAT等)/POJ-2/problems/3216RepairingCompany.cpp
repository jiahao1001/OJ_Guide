#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;
const int Q = 21;
const int M = 200;
const int INF = INT_MAX/2;
int dist[Q][Q];
int g[M][M];
int vis[M],ly[M];
int q,m;
bool dfs(int i){
    for(int j=0;j<m;j++)
        if(g[i][j] && !vis[j]){
            vis[j]= 1;
            if(ly[j]==-1 || dfs(ly[j])){
                ly[j] = i;
                return true;
            }
        }
    return false;
}
int max_match(){
    memset(ly,-1,sizeof ly);
    int mat = 0;
    for(int i=0;i<m;i++){
        memset(vis,0,sizeof vis);
        if(dfs(i)) mat++;
    }
    return mat;
}
int p[M],t[M],d[M];
int main()
{
    while(scanf("%d%d",&q,&m),q||m){
        for(int i=1;i<=q;i++)
            for(int j=1;j<=q;j++) {
                scanf("%d",&dist[i][j]);
                if(dist[i][j]==-1) dist[i][j] = INF;
            }
        //floyd
        for(int k=1;k<=q;k++)
            for(int i=1;i<=q;i++)
                for(int j=1;j<=q;j++)
                        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        //DAG
        memset(g,0,sizeof g);
        //ti+di+dist[i][j]<=tj
        
        for(int i=0;i<m;i++){
            scanf("%d%d%d",p+i,t+i,d+i);
        }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                if(t[i]+d[i]+dist[p[i]][p[j]]<=t[j]) g[i][j] = 1;
        printf("%d\n",m-max_match());
    }
    return 0;
}

