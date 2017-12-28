#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 101;
const int M = 10000;
const int INF = INT_MAX/2;
struct Edge{
    int u,v,w;
}elist[M];
bool operator<(const Edge &e1, const Edge &e2){
    return e1.w<e2.w;
}
int n,m;
int f[N],rank1[N];
void make_set(){
    for(int i=1;i<=n;i++)
        f[i] = i, rank1[i] = 0;
}
int find_set(int u){
    if(f[u]==u) return u;
    f[u] = find_set(f[u]);
    return f[u];
}
void union_set(int u,int v){
    u = find_set(u), v = find_set(v);
    if(u==v) return;
    if(rank1[u]<rank1[v]) f[u] = v;
    else{
        f[v] = u;
        if(rank1[u]==rank1[v]) rank1[u] ++;
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m){
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&elist[i].u,&elist[i].v,&elist[i].w);
        int best = INF;
        sort(elist,elist+m);
        for(int k=0;k<m;k++){
            //begin from edge k
            make_set();
            int cnt = 0;//tree edges
            for(int i=k;i<m;i++){
                int u = elist[i].u, v = elist[i].v;
                u = find_set(u), v = find_set(v);
                if(u==v) continue;
                union_set(u,v);
                cnt++;
                if(cnt==n-1){
                    best = min(best, elist[i].w - elist[k].w);
                    break;
                }
            }
            
        }
        
        
        
        if(best==INF) printf("-1\n");
        else printf("%d\n",best);
    }
    return 0;
}
