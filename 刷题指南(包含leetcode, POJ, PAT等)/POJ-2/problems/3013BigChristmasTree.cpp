#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 50001;
const long long INF = LLONG_MAX/2;
struct Edge{
    int v,nxt;
    long long w;
} elist[2*N];
int n,m;
long long w[N];//weight of node
int head[N];
int e_cnt;

long long dist[N];
int visited[N];

void addEdge(int u,int v,long long w){
    elist[e_cnt].v = v, elist[e_cnt].w = w;
    elist[e_cnt].nxt = head[u];
    head[u] = e_cnt++;
}
typedef pair<long long,int> PLLI;
int main()
{
    int a,b;
    long long c;
    int t;
    scanf("%d",&t);
    while(t--){
        e_cnt = 0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",w+i);
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++){
            scanf("%d%d%lld",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        for(int i=1;i<=n;i++) dist[i] = INF,visited[i] = 0;
        priority_queue<PLLI, vector<PLLI>, greater<PLLI> > heap;
        dist[1] = 0;
        heap.push(make_pair(0,1));
        //dijkstra
        while(!heap.empty()){
            PLLI  hd = heap.top();
            heap.pop();
            long long w = hd.first;
            int u = hd.second;
            if(dist[u]<w) continue;
            for(int i=head[u];i!=-1;i=elist[i].nxt){
                Edge &e = elist[i];
                if(dist[u]+e.w<dist[e.v]) dist[e.v] = dist[u] + e.w, heap.push(make_pair(dist[e.v],e.v));
            }
            
        }
        
        
        
        
        bool connected = true;
        for(int i=1;i<=n;i++) if(dist[i]==INF) connected = false;
        if(!connected){
            printf("No Answer\n");
        }else
        {
            long long answer = 0;
            for(int i=1;i<=n;i++) answer += dist[i]*w[i];
            printf("%lld\n",answer);
        }
        
    }
    return 0;
}
