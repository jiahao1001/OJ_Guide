#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string.h>
#include<stack>
#include<limits.h>
using namespace std;
const int N = 240;
const int INF = INT_MAX/2;
int K,C,M;
int g[N][N];

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


inline int floyd(){
    int r = 0;
    for(int k=1;k<=K+C;k++)
        for(int i=1;i<=K+C;i++)
            for(int j=1;j<=K+C;j++)
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]), r = max(r,g[i][j]);
    return r;
}
inline bool check(int d){
    Dinic dinic(K+C+2,0,K+C+1);
    for(int i=1;i<=K;i++) dinic.addEdge(0,i,M);
    for(int i=K+1;i<=K+C;i++) dinic.addEdge(i,K+C+1,1);
    for(int i=1;i<=K;i++)
        for(int j=K+1;j<=K+C;j++) if(g[j][i]<=d) dinic.addEdge(i,j,1);
    return dinic.maxflow()==C;
    //can milk, len<=d
}

int main(){
    scanf("%d%d%d",&K,&C,&M);
    for(int i=1;i<=K+C;i++)
        for(int j=1;j<=K+C;j++) {
            scanf("%d",&g[i][j]);
            if(!g[i][j]) g[i][j] = INF;
        }
    int l=0,mid;
    int r = floyd();
    while(l+1<r){
        mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%d\n",r);
    
    
}
