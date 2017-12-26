#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<string.h>
using namespace std;
const int N = 210;
const int inf = INT_MAX/2;
int src,sink;
int n,m;
int gold[N],store[N];
int d[N][N];
int pre[N],que[N];
int c[N][N];
int total;
bool bfs(){
    memset(pre,-1,sizeof pre);
    pre[src] = 0;
    int s,t;
    s=t=0;
    que[t++]=src;
    while(s<t){
        int u=que[s++];
        if(u==sink) return true;
        for(int v=0;v<=sink;v++)
            if(pre[v]==-1 && c[u][v]>0) pre[v] = u, que[t++] = v;
    }
    return false;
    
}
int maxflow(){
    int sum = 0,t;
    while(bfs()){
        t = inf;
        for(int p=sink;p!=src;p=pre[p]) t = min(c[pre[p]][p],t);
        for(int p=sink;p!=src;p=pre[p]) c[pre[p]][p]-=t, c[p][pre[p]]+=t;
        sum += t;
    }
    return sum;
}

inline bool check(int len){
    src = 0, sink = n+1;
    memset(c,0,sizeof c);
    for(int i=1;i<=n;i++)
        c[src][i] = gold[i];
    for(int i=1;i<=n;i++)
        c[i][sink] = store[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(d[i][j]<=len) c[i][j] = inf;
    return maxflow() == total;
}
int main()
{
    int u,v,w;
    while(scanf("%d",&n),n){
        total = 0;
        for(int i=1;i<=n;i++)
            scanf("%d",gold+i),total += gold[i];
        for(int i=1;i<=n;i++)
            scanf("%d",store+i);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) d[i][j] = inf;
        scanf("%d",&m);
        int l = 0, r = -1;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            d[u][v] = min(d[u][v],w);
            d[v][u] = min(d[v][u],w);
            r = max(r,w);
        }
        if(!check(r)){
            printf("No Solution\n");
            continue;
        }
        while(l+1<r){
            int mid = (l+r)>>1;
            if(check(mid)) r = mid;
            else l = mid;
        }
        printf("%d\n",r);
    }
    return 0;
}
