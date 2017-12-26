#include<iostream>
#include<string.h>
#include<stdio.h>
#include<limits.h>
#include<vector>
using namespace std;
const int N = 1010;
const int INF = INT_MAX/2;
int n,p,K;
struct Edge{
    int v,w;
    Edge(){}
    Edge(int _v,int _w):v(_v),w(_w){}
};
vector<Edge> g[N];
int dist[N];
int vis[N];
inline int w(int x,int len) {
    return x==INF?INF:x<=len?0:1;
}
inline bool check(int len){
    for(int i=1;i<=n;i++) dist[i] = INF,vis[i]=0;
    dist[1] = 0;
    //g[i][j]<=len 0, else 1
    //g[i][j]==inf inf
    for(int k=1;k<=n;k++){
        int best = INF, id = 0;
        for(int i=1;i<=n;i++)
            if(!vis[i] && dist[i]<=best) best = dist[i], id = i;
        vis[id] = 1;
        if(id==n) return dist[n]<=K;
        for(int i=0;i<g[id].size();i++){
            int v = g[id][i].v;
            int ww = g[id][i].w;
            if(!vis[v]&&dist[id]+w(ww,len)<dist[v]) dist[v] = dist[id]+w(ww,len);
        }
    }
    return dist[n]<=K;
}
int main()
{
    scanf("%d%d%d",&n,&p,&K);
    int a,b,ll;
    int l = 0, r = 0;
    for(int i=0;i<p;i++){
        scanf("%d%d%d",&a,&b,&ll);
        g[a].push_back(Edge(b,ll));
        g[b].push_back(Edge(a,ll));
        r = max(r,ll);
    }
    if(!check(r)){
        printf("-1\n");
        return 0;
    }
    if(check(0)){
        printf("0\n");
        return 0;
    }
    while(l+1<r){
        int mid = (l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n",r);
    return 0;
}
