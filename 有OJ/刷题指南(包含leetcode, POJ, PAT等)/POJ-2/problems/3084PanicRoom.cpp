
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
const int BIG = 5000;
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
        //cout<<"hello"<<endl;
        while(bfs()){
            fill(work.begin(),work.end(),0);
            result += dfs(s,INF);
            //cout<<"result"<<result<<endl;
        }
        return result;
    }
    
};
int main(){
    int t,m,n,tp,cnt;
    char s[10];
    scanf("%d",&t);
    while(t--){
        
        scanf("%d%d",&m,&n);
        n++;
        Dinic dinic(m+1,0,n);
        for(int i=1;i<=m;i++){
            scanf("%s%d",s,&cnt);
            if(s[0]=='I') dinic.addEdge(0, i, BIG);
            for(int j=0;j<cnt;j++){
                scanf("%d",&tp);
                tp++;
                dinic.addEdge(i, tp, BIG);
                dinic.addEdge(tp, i, 1);
            }
        }
        int f  = dinic.maxflow();
        if(f<BIG) printf("%d\n",f);
        else printf("PANIC ROOM BREACH\n");
    }
    return  0;
}
