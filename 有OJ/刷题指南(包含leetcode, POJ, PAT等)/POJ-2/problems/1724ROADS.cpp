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
#include<limits.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 110;
const int INF = INT_MAX/2;
int k,n,r;
int s,d,l,t;
struct Edge{
    int v,l,t;
    Edge(int _v,int _l,int _t):v(_v),l(_l),t(_t){}
    Edge(){}
};
vector<Edge> g[N];
int dist[N];

void A_star()
{
    for(int i=1;i<=n;i++) dist[i] = INF;
    dist[1] = 0;
    priority_queue<pair<PII,int>,vector<pair<PII,int> >, greater<pair<PII,int> > > pq;
    pq.push(make_pair(make_pair(0,1),0));
    //PII total money, v, dist
    while(!pq.empty())
    {
        pair<PII,int> head = pq.top();
        pq.pop();
        int u = head.first.second;
        int m = head.first.first;
        int d = head.second;
        if(d>dist[u]) continue;
        if(d<dist[u]) dist[u] = d;
        for(int i=0;i<g[u].size();i++){
            Edge &e = g[u][i];
            if(m+e.t<=k) {
                pq.push(make_pair(make_pair(m+e.t,e.v),d+e.l));
                //printf("push (%d,%d)\n",m+e.t,e.v);
            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&k,&n,&r);
    for(int i=0;i<r;i++){
        scanf("%d%d%d%d",&s,&d,&l,&t);
        g[s].push_back(Edge(d,l,t));
    }
    A_star();
    if(dist[n]==INF)printf("-1\n");
    else printf("%d\n",dist[n]);
    return 0;
}
