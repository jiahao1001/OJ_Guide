#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
const int MAXN = 10010;
struct Edge{
    int v,w;
    int id;
    Edge(){}
    Edge(int i,int _v,int _w):id(i),v(_v),w(_w){}
};
vector<Edge> g[MAXN];
int N;
char cmd[20];
struct Node{
    int min,max,neg;
}tree[MAXN*4];
int f[MAXN], size[MAXN], dep[MAXN];
int w[MAXN],top[MAXN];
int son[MAXN],sonlen[MAXN],soneid[MAXN];
int tot;
int e_on[MAXN];
void push_down(int rt,int l,int r){
    if(tree[rt].neg){
        tree[rt*2].min = - tree[rt*2].min;
        tree[rt*2].max = - tree[rt*2].max;
        swap(tree[rt*2].min,tree[rt*2].max);
        
        tree[rt*2+1].min = - tree[rt*2+1].min;
        tree[rt*2+1].max = - tree[rt*2+1].max;
        swap(tree[rt*2+1].min,tree[rt*2+1].max);
        
        tree[rt*2].neg ^= 1;
        tree[rt*2+1].neg ^= 1;
        tree[rt].neg^=1;
    }
}
void update(int rt){
    tree[rt].min = min(tree[rt*2].min,tree[rt*2+1].min);
    tree[rt].max = max(tree[rt*2].max, tree[rt*2+1].max);
}
void insert(int rt,int l,int r,int ll,int rr,int v){
    if(ll<=l && rr>=r){
        tree[rt].min = tree[rt].max = v;
        return;
    }
    int m = (l+r)>>1;
    push_down(rt,l,r);
    if(ll<=m) insert(rt*2,l,m,ll,rr,v);
    if(rr>=m+1) insert(rt*2+1,m+1,r,ll,rr,v);
    update(rt);
}

void dfs(int u,int fa,int d){
    dep[u] = d;
    size[u] = 1;
    f[u] = fa;
    int best = INT_MIN;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].v;
        if(v==fa) continue;
        dfs(v,u,d+1);
        size[u] += size[v];
        if(size[v]>best) best = size[v], son[u] = v,sonlen[u] = g[u][i].w,soneid[u]=g[u][i].id;
    }
}
void dfs1(int u,int fa,int tp,int len,int id){
    top[u] = tp;
    insert(1,1,N,tot,tot,len);
    e_on[id] = tot;
    w[u] = tot++;
    if(son[u]) dfs1(son[u],u,tp,sonlen[u],soneid[u]);
    for(int i=0;i<g[u].size();i++){
        Edge &e = g[u][i];
        int v = e.v, ww = e.w;
        if(v==son[u] || v==fa) continue;
        dfs1(v,u,v,ww,e.id);
    }
    
}
int get(int rt,int l,int r,int ll,int rr){
    //get the max
    if(ll<=l && rr>=r) return tree[rt].max;
    int ret = INT_MIN;
    push_down(rt,l,r);
    int m = (l+r)>>1;
    if(ll<=m) ret = max(ret,get(rt*2,l,m,ll,rr));
    if(rr>=m+1) ret = max(ret,get(rt*2+1,m+1,r,ll,rr));
    return ret;
}
int query(int u,int v){
    int f1 = top[u], f2 = top[v];
    int ret = INT_MIN;
    while(f1!=f2){
        if(dep[f1]<dep[f2]) swap(f1,f2),swap(u,v);
        ret = max(ret, get(1,1,N,w[f1],w[u]));
        u = f[f1], f1 = top[u];
    }
    if(u==v) return ret;
    if(dep[u]>dep[v]) swap(u,v);
    return max(ret,get(1,1,N,w[son[u]],w[v]));
}
void neg(int rt,int l,int r,int ll,int rr){
    if(ll<=l && rr>=r){
        tree[rt].min = - tree[rt].min;
        tree[rt].max = - tree[rt].max;
        swap(tree[rt].min,tree[rt].max);
        tree[rt].neg ^= 1;
        return;
    }
    int m = (l+r)>>1;
    push_down(rt,ll,rr);
    if(ll<=m) neg(rt*2,l,m,ll,rr);
    if(rr>=m+1) neg(rt*2+1,m+1,r,ll,rr);
    update(rt);
    
}

void negate1(int u,int v){
    int f1 = top[u], f2 = top[v];
    int ret = INT_MIN;
    while(f1!=f2){
        if(dep[f1]<dep[f2]) swap(f1,f2),swap(u,v);
        neg(1,1,N,w[f1],w[u]);
        u = f[f1], f1 = top[u];
    }
    if(u==v) return;
    if(dep[u]>dep[v]) swap(u,v);
    neg(1,1,N,w[son[u]],w[v]);
}






int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(tree,0,sizeof(tree));
        memset(son,0,sizeof son);
        scanf("%d",&N);
        for(int i=1;i<=N;i++) g[i].clear();
        int u,v,w;
        for(int i=1;i<N;i++){
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(Edge(i,v,w));
            g[v].push_back(Edge(i,u,w));
        }
        dfs(1,0,0);//size, dep, f
        tot = 1;
        dfs1(1,0,1,0,0);
        while(scanf("%s",cmd),strcmp(cmd,"DONE")){
            scanf("%d%d",&u,&v);
            if(!strcmp(cmd,"QUERY")){
                printf("%d\n",query(u,v));
            }
            else if(!strcmp(cmd,"CHANGE")){
                insert(1,1,N,e_on[u],e_on[u],v);
            }else{
                //negate1
                negate1(u,v);
            }
        }
    }
    return 0;
}
