
#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
const int INF = INT_MAX/2;

struct Dinic{
    int n,s,t;
    struct Edge{
        int v,capacity,inv;
        Edge(int _v,int _capacity, int _inv):v(_v),capacity(_capacity),inv(_inv){}
    };
    vector<vector<Edge> > edges;
    vector<int> q;
    vector<int> work;
    vector<int> dist;
    Dinic(int n,int s,int t){
        edges.resize(n);
        q.resize(n);
        work.resize(n);
        dist.resize(n);
        this->n = n, this->s = s, this->t = t;
        
    }
    bool bfs(){
        fill(dist.begin(),dist.end(),-1);
        dist[s] = 0;
        int tail = 0;
        q[tail++] = s;
        int head = 0;
        while(head<tail){
            int u = q[head];
            int v = 0;
            for(int i=0;i<edges[u].size();i++){
                v = edges[u][i].v;
                if(edges[u][i].capacity>0 && dist[v]==-1)
                    dist[v] = dist[u]+1, q[tail++] = v;
            }
            head++;
        }
        return dist[t]!=-1;
    }
    int dfs(int u,int lim){
        if(u==t) return lim;
        int f = 0;
        for(int &i=work[u];i<edges[u].size();i++){
            int v = edges[u][i].v;
            if(edges[u][i].capacity<=0 || dist[v]!=dist[u]+1)
                continue;
            int nf=dfs(v,min(lim,edges[u][i].capacity));
            if(nf>0)
            {
                edges[u][i].capacity -= nf;
                edges[v][edges[u][i].inv].capacity += nf;
                f += nf;
                lim -= nf;
                if(lim==0) break;
            }
        }
        return f;
    }
    void addEdge(int u,int v,int capacity){
        edges[u].push_back(Edge(v,capacity,edges[v].size()));
        edges[v].push_back(Edge(u,0,edges[u].size()-1));
    }
    int maxflow(){
        int result = 0;
        while(bfs()){
            fill(work.begin(),work.end(),0);
            result += dfs(s,INF);
        }
        return result;
    }
    
};
int main(){
    int p,n,x;
    unsigned int in[50],in2[50],out[50];
    memset(in,0,sizeof(in));
    memset(in2,0,sizeof(in2));
    memset(out,0,sizeof(out));
    int pf[50];
    scanf("%d%d",&p,&n);
    for(int i=0;i<n;i++){
        scanf("%d",pf+i);
        for(int j=0;j<p;j++){
            scanf("%d",&x);
            if(x==2) in2[i]|=(1<<j);
            else in[i]|=(x<<j);
        }
        for(int j=0;j<p;j++){
            scanf("%d",&x);
            out[i]|=(x<<j);
        }
    }
    Dinic dinic(2*n+2,2*n,2*n+1);
    for(int i=0;i<n;i++){
        dinic.addEdge(i, i+n, pf[i]);
        if(in[i]==0) dinic.addEdge(2*n, i, INF);
        if(out[i]+1 == (1<<p)) dinic.addEdge(i+n, 2*n+1, INF);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if((out[i] &(~in2[j])) == in[j]) dinic.addEdge(i+n, j, INF);
        }
    int f = dinic.maxflow();
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int k=0;k<dinic.edges[i+n].size();k++){
            if(dinic.edges[i+n][k].v!=2*n+1 &&dinic.edges[i+n][k].v != i && dinic.edges[i+n][k].capacity<INF) cnt++;
        }
    }
    printf("%d %d\n",f,cnt);
    for(int i=0;i<n;i++){
        for(int k=0;k<dinic.edges[i+n].size();k++){
            if(dinic.edges[i+n][k].v!=2*n+1 &&dinic.edges[i+n][k].v != i && dinic.edges[i+n][k].capacity<INF) {
                printf("%d %d %d\n",i+1,dinic.edges[i+n][k].v+1, INF-dinic.edges[i+n][k].capacity);
            }
        }
    }
}
