
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
inline int sqr(int x){
    return x*x;
}
char pm[20][30], lm[20][30];
int main(){
    int t,n,m,d;
    scanf("%d",&t);
    for(int q=1;q<=t;q++){
        printf("Case #%d: ",q);
        scanf("%d%d",&n,&d);
        for(int i=0;i<n;i++){
            scanf("%s",pm[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%s",lm[i]);
        }
        int total = 0;
        m = strlen(pm[0]);
        int N = n*m;
        Dinic dinic(2*N+2,2*N,2*N+1);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(lm[i][j]=='L') dinic.addEdge(2*N, i*m+j, 1), total++;
                if(pm[i][j]!='0') {
                    dinic.addEdge(i*m+j, i*m+j+N, pm[i][j]-'0');
                    if(min(min(i+1,n-i),min(j+1,m-j))<=d) dinic.addEdge(i*m+j+N, 2*N+1, INF);
                }
            }
        //jump
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(pm[i][j]=='0') continue;
                for(int ii=max(0,i-d);ii<=min(n-1,i+d);ii++)
                    for(int jj=max(0,j-d);jj<=min(m-1,j+d);jj++){
                        if(pm[ii][jj]!='0' && sqr(i-ii)+sqr(j-jj)<=sqr(d)) dinic.addEdge(i*m+j+N, ii*m+jj, INF);
                    }
            }
        int died =total-dinic.maxflow();
        if(died==0) printf("no lizard was left behind.\n");
        else if(died==1) printf("1 lizard was left behind.\n");
        else printf("%d lizards were left behind.\n",died);
        
    }
    return  0;
}
