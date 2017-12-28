#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
const int N = 202;
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
    void init(int n,int s,int t){
        edges.resize(n);
        q.resize(n);
        work.resize(n);
        dist.resize(n);
        edges.clear();
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
struct Edge{
    int v,w;
    Edge(int _v,int _w):v(_v),w(_w){}
    Edge(){}
};
vector<Edge> g[N];
int n,p,t;
Dinic dinic;
inline bool check(int w){
    //e.w <= w
    //flow == t
    dinic.init(n+2,0,n+1);
    dinic.addEdge(0,1,t);
    dinic.addEdge(n,n+1,t);
    for(int i=1;i<=n;i++)
        for(int j=0;j<g[i].size();j++){
            Edge &e = g[i][j];
            if(e.w<=w) dinic.addEdge(i,e.v,1);
        }
    
    return dinic.maxflow()==t;
}
int main()
{
    
    int u,v,w;
    scanf("%d%d%d",&n,&p,&t);
    int l=0, r = INT_MIN;
    for(int i=0;i<p;i++){
        scanf("%d%d%d",&u,&v,&w);
        r = max(r,w);
        g[u].push_back(Edge(v,w));
        g[v].push_back(Edge(u,w));
    }
    int mid;
    while(l+1<r){
        mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%d\n",r);
    return 0;
}
