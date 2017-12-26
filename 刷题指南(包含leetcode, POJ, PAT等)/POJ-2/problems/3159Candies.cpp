#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;
const int N = 30010;
const int M = 150010;
const int INF = 0x3f3f3f3f;
struct Edge{
    int v, w, next;
}elist[M];
int head[N];
int e_cnt = 1;

//d[u]+w(u,v)>=d[v]
//A B c  candies[B]-candies[A]<=c
// A->B  c
void addedge(int u,int v,int w){
    elist[e_cnt].v = v, elist[e_cnt].w=w, elist[e_cnt].next = head[u];
    head[u] = e_cnt++;
}
int dist[N];
int vis[N];
int n,m;
int A,B,c;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&A,&B,&c);
        addedge(A,B,c);
    }
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    dist[1] = 0;
    vis[1]=1;
    stack<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int u = Q.top();
        Q.pop();
        for(int i=head[u];i;i=elist[i].next){
            Edge &e = elist[i];
            if(dist[u]+e.w<dist[e.v]) {
                dist[e.v] = dist[u]+e.w;
                if(!vis[e.v]) Q.push(e.v), vis[e.v]=1;
            }
        }
        vis[u]=0;
    }
    printf("%d\n",abs(dist[n]));
    return 0;
    
}
