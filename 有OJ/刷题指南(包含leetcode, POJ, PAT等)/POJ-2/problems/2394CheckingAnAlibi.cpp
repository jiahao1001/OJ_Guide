#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int INF  = INT_MAX/2;
const int N = 501;
int g[N][N];
int F,P,C,M;
int cow[101];
int dist[N];
int cnt;
int visited[N];
int main()
{
    int u,v,w;
    scanf("%d%d%d%d",&F,&P,&C,&M);
    for(int i = 1;i<=F;i++)
        for(int j=1;j<=F;j++) g[i][j] = INF;
    for(int i=0;i<P;i++){
        scanf("%d%d%d",&u,&v,&w);
        g[u][v] = min(g[u][v],w);
        g[v][u] = min(g[v][u],w);
    }
    for(int i=1;i<=C;i++)
        scanf("%d",cow+i);
    //dijkstra
    for(int i=1;i<=F;i++) dist[i] = INF-1,visited[i] = 0;
    dist[1] = 0;
    for(int k=1;k<=F;k++){
        int best = INF, id = 0;
        for(int i=1;i<=F;i++)
            if(!visited[i] && best>dist[i]) best = dist[i], id = i;
        visited[id] = 1;
        for(int i=1;i<=F;i++)
            if(!visited[i] && dist[id]+g[id][i]<dist[i]) dist[i] = dist[id]+g[id][i]; 
    }
    cnt = 0;
    for(int i=1;i<=C;i++) if(dist[cow[i]]<=M) cnt++;
    printf("%d\n",cnt);
    for(int i=1;i<=C;i++) if(dist[cow[i]]<=M) printf("%d\n",i);
    return 0;
}
