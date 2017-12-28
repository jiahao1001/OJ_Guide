#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
using namespace std;
const int N = 500;
int g[N][N];
int n,m;
int valid[N];//vertex still in shrinkd graph
int visited[N];
int V;
int w[N];
int min_cut_phase(int a){
    memset(visited,0,sizeof(visited));
    memset(w,0,sizeof(w));
    visited[a] = 1;
    for(int i=0;i<n;i++)
        if(i!=a && valid[i]) w[i] = g[a][i];
    int last;
    int u,v;//need merge u and v
    for(int k=1;k<V;k++){
        int best = INT_MIN, id = 0;
        for(int i=0;i<n;i++)
            if(valid[i] && !visited[i] && w[i]>best) best = w[i],id=i;
        visited[id] = 1;
        last = best;
        u = v, v = id;
        for(int i=0;i<n;i++)
            if(valid[i] && !visited[i]) w[i]+=g[i][id];
    }
    valid[v] = 0;
    for(int i=0;i<n;i++)
        if(valid[i]&&i!=u)
            g[u][i]=g[i][u] = g[u][i]+g[v][i];
    //printf("merge %d %d->%d\n",u,v,last);
    
    return last;
}


int stoer_wagner()
{
    int a = 0;
    V = n;
    for(int i=0;i<n;i++) valid[i] = 1;
    int cut = INT_MAX;
    while(V>1){
        cut=min(cut,min_cut_phase(a));
        V--;
    }
    return cut;
}
int main()
{
    int u,v,w;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(g,0,sizeof(g));
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            g[u][v] +=w,g[v][u] += w;
        }
        
        printf("%d\n",stoer_wagner());
    }
    return 0;
}
