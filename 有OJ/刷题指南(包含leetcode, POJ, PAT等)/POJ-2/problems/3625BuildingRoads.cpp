#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
#include<float.h>
#include<math.h>
#include<sstream>
#include<stdlib.h>
#include<limits.h>
#include<string>
#include<numeric>
#include<map>
using namespace std;
const int N = 1000;
int n,m;
int x[N],y[N];
int f[N],rank[N];
void make_set(){
    for(int i=0;i<n;i++) f[i]=i,rank[i]=0;
}
double hypot(double x,double y){
    return sqrt(x*x+y*y);
}
struct Edge{
    double d;
    int u,v;
    Edge(double _d,int _u,int _v):d(_d),u(_u),v(_v){}
    Edge(){}
};
bool operator<(const Edge& e1,const Edge& e2){
    return e1.d>e2.d;
}
int find_set(int u){
    if(f[u]==u) return u;
    f[u] = find_set(f[u]);
    return f[u];
}
void union_set(int u,int v){
    u = find_set(u), v = find_set(v);
    if(u==v) return;
    if(rank[u]<rank[v]) f[u]=v;
    else{
        f[v] = u;
        if(rank[u]==rank[v]) rank[u]++;
    }
}

int main()
{
    int u,v;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%d",x+i,y+i);
    }
    priority_queue<Edge> pq;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) pq.push(Edge(hypot(1.0*x[i]-x[j],1.0*y[i]-y[j]),i,j));
    make_set();
    int e_cnt = 0;
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        u--,v--;
        u = find_set(u), v=find_set(v);
        if(u!=v){
            e_cnt++;
            union_set(u,v);
        }
    }
    
    double cost = 0;
    for(int i=0;i<n*n;i++){
        Edge e = pq.top();
        pq.pop();
        u = e.u, v = e.v;
        u = find_set(u), v = find_set(v);
        if(u!=v){
            cost += e.d;
            //cout<<e.d<<endl;
            e_cnt++;
            union_set(u,v);
        }
        if(e_cnt==n-1) break;
    }
    printf("%.2f\n",cost);
    return 0;
}
