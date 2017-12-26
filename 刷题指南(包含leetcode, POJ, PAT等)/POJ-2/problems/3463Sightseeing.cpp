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
#include<numeric>
#include<map>

using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
const int M = 10000;
const int INF = INT_MAX/2;
struct Edge{
    int v,w;
    Edge(int _v,int _w):v(_v),w(_w){}
};
vector<Edge> g[N];
int n,m,S,F;
int dist[N][2];
int dp[N][2];
int vis[N][2];
void dijkstra(){
    priority_queue<PII,vector<PII>,greater<PII> > pq;
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) {
        dist[i][0] = dist[i][1] = INF;
    }
    dist[S][0] = 0, dp[S][0] = 1;
    int v,w;
    for(int k=1;k<=2*n;k++){
        int min_w = INF;
        int id, c;
        for(int i=1;i<=n;i++){
            if(!vis[i][0]){
                if(min_w>dist[i][0]) min_w=dist[i][0],id=i,c=0;
            }
            if(!vis[i][1]){
                if(min_w>dist[i][1]) min_w=dist[i][1],id=i,c=1;
            }
        }
        vis[id][c] = 1;
        for(int i=0;i<g[id].size();i++){
            Edge &e = g[id][i];
            v = e.v, w= e.w;
            if(!vis[v][0] && dist[v][0]>=dist[id][c]+w){
                if(dist[v][0]==dist[id][c]+w) dp[v][0] += dp[id][c];
                else{
                    dist[v][1] = dist[v][0];
                    dist[v][0]=dist[id][c]+w;
                    dp[v][1] = dp[v][0];
                    dp[v][0] = dp[id][c];
                    
                }
            }else if(!vis[v][1]&&dist[v][1]>=dist[id][c]+w){
                if(dist[v][1]==dist[id][c]+w) dp[v][1]+=dp[id][c];
                else{
                    dist[v][1] = dist[id][c]+w;
                    dp[v][1] = dp[id][c];
                }
            }
        }
        
    }
                
    
    
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int u,v,w;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(Edge(v,w));
        }
        scanf("%d%d",&S,&F);
        dijkstra();
        if(dist[F][0]==dist[F][1]-1)
            printf("%d\n",dp[F][0]+dp[F][1]);
        else printf("%d\n",dp[F][0]);
    }
}
