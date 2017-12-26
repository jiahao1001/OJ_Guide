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
const int N = 201;
const long long L_INF = LLONG_MAX/2;
int cow[N],shelter[N];
long long dist[N][N];
int n,m;
int cnt;
long long d[N*N];

int total_cow;
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
Dinic dinic;
inline bool check(long long len){
    //<=len reachable
    dinic.init(2*n+2,0,2*n+1);
    for(int i=1;i<=n;i++)
        dinic.addEdge(0,i,cow[i]);
    for(int i=1;i<=n;i++)
        dinic.addEdge(n+i,2*n+1,shelter[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dist[i][j]<=len) dinic.addEdge(i,n+j,INF);
    return dinic.maxflow()==total_cow;
}
int main()
{
    scanf("%d%d",&n,&m);
    int u,v;
    total_cow = 0;
    long long w;
    for(int i=1;i<=n;i++)
        scanf("%d%d",cow+i,shelter+i), total_cow+=cow[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dist[i][j] = L_INF;
    for(int i=1;i<=n;i++) dist[i][i] = 0;
    for(int i=1;i<=m;i++){
        scanf("%d%d%lld",&u,&v,&w);
        dist[u][v] = min(dist[u][v],w);
        dist[v][u] = min(dist[v][u],w);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
    cnt = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) d[cnt++] = dist[i][j];
    sort(d,d+cnt);
    cnt = unique(d,d+cnt)-d;
    if(!check(d[cnt-1])){
        printf("-1\n");
        return 0;
    }
    if(check(d[0])){
        printf("0\n");
        return 0;
    }
    int l=0,r=cnt-1;
    int mid;
    while(l+1<r){
        mid = (l+r)>>1;
        if(check(d[mid])) r=mid;
        else l=mid;
    }
    if(d[r]==L_INF) printf("-1\n");
    else printf("%lld\n",d[r]);
    return 0;
}
