#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
#include<float.h>
#include<math.h>
#include<sstream>
#include<stdlib.h>
#include<limits.h>
#include<string>
#include<assert.h>
#include<numeric>
#include<map>
using namespace std;
const int N = 105;
const int INF = 0x3f3f3f3f;
int n,m;
int g[N][N];
int vis[N];
int dist[N];
int prim(){
    memset(vis,0,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    dist[1] = 0;
    int cost = 0;
    int id,best;
    for(int k=0;k<n;k++){
        best = INF;
        for(int i=1;i<=n;i++) if(!vis[i] && dist[i]<best) best = dist[i],id=i;
        cost += dist[id];
        vis[id] = 1;
        for(int i=1;i<=n;i++) if(!vis[i] && g[id][i]<dist[i]) dist[i]=g[id][i];
    }
    return cost;
}
int main(){
    int u,v,w;
    while(scanf("%d",&n),n){
        scanf("%d",&m);
        memset(g,0x3f,sizeof(g));
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            g[u][v] = min(g[u][v],w);
            g[v][u] = min(g[v][u],w);
        }
        printf("%d\n",prim());
    }
    return 0;
}
