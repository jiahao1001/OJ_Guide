
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <set>
#include <ctime>
#include <utility>
using namespace std;
#define INF 1e9
#define eps 0x7fffffff
#define N 100010

struct node
{
    int l,r,f;
    int w,sum,rev;
}p[N];

int A[N],B[N];

inline bool isroot(int u)
{return(!p[u].f || (p[p[u].f].l != u && p[p[u].f].r != u));}

inline void push(int x)
{
    if (!x) return ;
    if (p[x].rev)
    {
        p[p[x].l].rev ^= 1;
        swap(p[p[x].l].l, p[p[x].l].r);
        p[p[x].r].rev ^= 1;
        swap(p[p[x].r].l, p[p[x].r].r);
        p[x].rev = false;
    }
}
inline void update(int x){
    p[x].sum = p[x].w+p[p[x].l].sum + p[p[x].r].sum;
}

inline void zig(int x)
{
    int y = p[x].f,z = p[y].f;
    push(y);
    push(x);
    if (z)
        if (p[z].l == y) p[z].l = x;
        else if (p[z].r == y) p[z].r = x;
    p[x].f = z;
    p[y].l = p[x].r; p[p[x].r].f = y;
    p[x].r = y; p[y].f = x;
    update(y);
}

inline void zag(int x)
{
    int y = p[x].f,z = p[y].f;
    push(y);
    push(x);
    if (z)
        if (p[z].l == y) p[z].l = x;
        else if (p[z].r == y) p[z].r = x;
    p[x].f = z;
    p[y].r = p[x].l; p[p[x].l].f = y;
    p[x].l = y; p[y].f = x;
    update(y);
}

void splay(int x)
{
    push(x);
    update(x);
    while (!isroot(x))
    {
        int y = p[x].f,z = p[y].f;
        if (isroot(y))
            if (p[y].l == x) zig(x);
            else zag(x);
            else if (p[z].l == y)
                if (p[y].l == x) zig(y),zig(x);
                else zag(x),zig(x);
                else if (p[z].r == y)
                    if (p[y].r == x) zag(y),zag(x);
                    else zig(x),zag(x);
    }
    update(x);
}

int access(int v)
{
    splay(v);
    p[v].r = 0;
    update(v);
    int w;
    int last = v;
    while (w=p[v].f)
    {
        splay(w);
        last = w;
        p[w].r = v;
        splay(v);
    }
    return last;
}

void makeroot(int u)
{
    access(u);
    p[u].rev ^= 1;
    swap(p[u].l,p[u].r);
}

void link(int u,int v)
{//u is the root
    access(u);
    p[u].f = v;
   // access(u);
}
int LCA(int u,int v){
    access(u);
    return access(v);
}
int query(int u,int v){
    int x = LCA(u,v);
    //cout<<"LCA for"<<u<<" "<<v<<"is"<<x<<endl;
    
    access(x);
    int sum=-2*p[x].sum;
    access(v);
    sum+=p[v].sum;
    access(u);
    sum+=p[u].sum;
    return sum;
}
void change(int u,int v,int w){
    access(u);
    splay(v);
    int d;
    if(p[v].f==u){
        d = w-p[v].w;
        p[v].sum += d;
        p[v].w += d;
        access(v);
        return;
    }
    access(v);
    splay(u);
    d = w-p[u].w;
    p[u].sum += d;
    p[u].w += d;
    access(u);
}
vector<pair<int,int> > adj[N];
void dfs(int u,int f,int w){
    //cout<<"("<<u<<" "<<f<<")"<<endl;
    if(f){
        p[u].w+=w;
        p[u].sum += w;
        link(u,f);
    }
    for(int i=0;i<adj[u].size();i++)
        if(adj[u][i].first!=f){
            dfs(adj[u][i].first,u,adj[u][i].second);
        }
}
int main()
{
    int n,q,s,w,qu,u,r;
    scanf("%d%d%d",&n,&q,&s);
    for(int i=0;i<n-1;i++){
        scanf("%d%d%d",A+i,B+i,&w);
        adj[A[i]].push_back(make_pair(B[i],w));
        adj[B[i]].push_back(make_pair(A[i], w));
    }
    dfs(1,0,0);
    
    for(int i=0;i<q;i++){
        scanf("%d",&qu);
        if(qu==0){
            scanf("%d",&u);
            printf("%d\n",query(s,u));
            s=u;
        }else{
            scanf("%d%d",&r,&w);
            r--;
            change(A[r],B[r],w);
        }
    }
    
    return 0;
}
