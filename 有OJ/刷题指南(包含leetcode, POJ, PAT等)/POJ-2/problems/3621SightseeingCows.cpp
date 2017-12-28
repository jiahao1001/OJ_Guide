#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<math.h>
#include<limits.h>
using namespace std;
const double eps = 1e-7;
const int P = 5000;
const int L = 1001;
int l,p;
int fun[L];
struct Edge{
    int u,v,w;
}elist[P];
int bellman_ford(double x){
    double dist[L];
    for(int i=1;i<=l;i++) dist[i] = 0;
    bool ok = false;
    for(int i=1;i<l;i++){
        ok = true;
        for(int j=0;j<p;j++){
            Edge &e = elist[j];
            int u = e.u;
            int v = e.v;
            double w = e.w*x - fun[v];
            if(dist[u]+w<dist[v]) dist[v] = dist[u]+w,ok = false;
        }
        if(ok) break;
    }
    for(int j=0;j<p;j++){
        Edge &e = elist[j];
        int v = e.v;
        int u = e.u;
        double w = e.w*x - fun[v];
        if(dist[u]+w<dist[v]) return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&l,&p);
    for(int i=1;i<=l;i++)
        scanf("%d",fun+i);
    int u,v,w;
    for(int i=0;i<p;i++){
        scanf("%d%d%d",&u,&v,&w);
        elist[i].u = u, elist[i].v=v, elist[i].w = w;
    }
    double l = 0.0, r = 1000.0;
    double mid;
    while(fabs(l-r)>eps){
        mid = (l+r)/2;
        if(bellman_ford(mid)) l = mid;
        else r = mid;
    }
    printf("%.2f\n",l);
    return 0;
}
