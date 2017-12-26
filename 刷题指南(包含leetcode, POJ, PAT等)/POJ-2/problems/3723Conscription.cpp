#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
const int N = 20000;
int n,m;
int R,x,y,d;
struct Edge{
    int u,v;
    int w;
}elist[50000];
bool operator<(const Edge &e1, const Edge &e2){
    return e1.w>e2.w;
}
int f[N],rank1[N];
int find(int x){
    if(f[x]==x) return x;
    f[x] = find(f[x]);
    return f[x];
}
void _union(int u,int v){
    if(rank1[u]<rank1[v]) f[u]  =v;
    else{
        f[v] = u;
        if(rank1[u]==rank1[v]) rank1[u]++;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&R);
        for(int i=0;i<R;i++){
            scanf("%d%d%d",&x,&y,&d);
            elist[i].u = x, elist[i].v = n+y;
            elist[i].w = d;
        }
        int money = 10000*(n+m);
        int discount = 0;
        sort(elist,elist+R);
        for(int i=0;i<n+m;i++)
            f[i] = i, rank1[i] = 0;
        for(int i=0;i<R;i++){
            int u = find(elist[i].u);
            int v = find(elist[i].v);
            if(u==v) continue;
            _union(u,v);
            discount += elist[i].w;
        }
        printf("%d\n",money-discount);
    }
}
