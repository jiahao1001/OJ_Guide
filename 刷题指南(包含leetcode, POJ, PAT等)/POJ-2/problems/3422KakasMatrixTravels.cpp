#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<string.h>
using namespace std;
const int E =40100;;
const int N = 5100;
const int INF = INT_MAX/2;
struct Edge{
    int u,v,next;
    int cost,cap;
}elist[E];
int head[N];
int pre[N];
int dist[N];
int inqueue[N];
int que[N*N];
int e_cnt;
int n,src,sink;
void init(int _n,int _src,int _sink){
    n = _n, src = _src, sink = _sink;
    e_cnt = 0;
    for(int i=0;i<n;i++) head[i] = -1;
}
void addEdge(int u,int v,int cost,int cap){
    elist[e_cnt].u = u, elist[e_cnt].v = v, elist[e_cnt].cost = cost,elist[e_cnt].cap=cap;
    elist[e_cnt].next = head[u];
    head[u] = e_cnt++;
    elist[e_cnt].u = v, elist[e_cnt].v = u, elist[e_cnt].cost = -cost, elist[e_cnt].cap = 0;
    elist[e_cnt].next = head[v];
    head[v] = e_cnt++;
}
int cost(){
    int total = 0;
    while(true){
        //bellman-ford
        for(int i=0;i<n;i++) dist[i] = INT_MIN/2,inqueue[i] = 0;
        dist[src] = 0;
        int s=0,t=0;
        que[t++] = src;
        inqueue[src] = 1;
        while(s<t){
            int u = que[s++];
            inqueue[u] = 0;
            for(int j=head[u];j!=-1;j=elist[j].next){
                Edge &e = elist[j];
                if(e.cap!=0 && dist[e.u]+e.cost>dist[e.v]){
                    dist[e.v] = dist[e.u] + e.cost;
                    pre[e.v] = j;
                    if(!inqueue[e.v]) que[t++] = e.v, inqueue[e.v]=1;
                }
            }
        }
        if(dist[sink]==INT_MIN/2) break;
        total += dist[sink];
        //cout<<dist[sink]<<endl;
        //augment
        int f = INF;
        for(int i=sink;i!=src;i=elist[pre[i]].u){
            f = min(elist[pre[i]].cap,f);
        }
        //cout<<"flow "<<f<<endl;
        for(int i=sink;i!=src;i=elist[pre[i]].u){
            elist[pre[i]].cap-=f;
            elist[pre[i]^1].cap+=f;
        }
        
    }
    
    return total;
}



int M[51][51];
int main()
{
    int nn,k;
    scanf("%d%d",&nn,&k);
    for(int i=0;i<nn;i++)
        for(int j=0;j<nn;j++){
            scanf("%d",&M[i][j]);
        }
    if(k==0){
        printf("0\n");
        return 0;
    }
    int off = nn*nn;
    init(2*nn*nn,0,2*nn*nn-1);
    int id;
    for(int i=0;i<nn;i++)
        for(int j=0;j<nn;j++){
            id = i*nn+j;
            addEdge(id,off+id,M[i][j],1);
            addEdge(id,off+id,0,k-1);
            if(j+1<nn) addEdge(off+id,i*nn+j+1,0,k);
            if(i+1<nn) addEdge(off+id,(i+1)*nn+j,0,k);
            
        }
    printf("%d\n",cost());
    
    return 0;
}
