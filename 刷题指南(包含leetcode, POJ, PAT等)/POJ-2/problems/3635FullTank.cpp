#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 1000;
int n,m,q;
int price[N];
struct Edge{
    int v,d;
    Edge(){}
    Edge(int _v,int _d):v(_v),d(_d){}
};
vector<Edge> g[N];
typedef pair<int,pair<int,int> > config_t;//cost, city, fuel
int visited[N][101];
int c,s,ee;
int bfs(){
    config_t initial = make_pair(0,make_pair(s,0));
    memset(visited,0,sizeof visited);
    visited[s][0] = 1;
    priority_queue<config_t,vector<config_t>, greater<config_t> > Q;
    Q.push(initial);
    while(!Q.empty()){
        config_t head = Q.top();
        Q.pop();
        int cost = head.first, city = head.second.first, fuel = head.second.second;
        visited[city][fuel] = 1;
        if(city==ee) return cost;
        //add fuel
        if(fuel<c && !visited[city][fuel+1]){
            Q.push(make_pair(cost+price[city],make_pair(city,fuel+1)));
        }
        for(int i=0;i<g[city].size();i++){
            Edge &e = g[city][i];
            if(fuel>=e.d && !visited[e.v][fuel-e.d]){
                Q.push(make_pair(cost,make_pair(e.v,fuel-e.d)));
            }
        }
        
    }
    
    return -1;
}


int main()
{
    int u,v,d;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",price+i);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&d);
        g[u].push_back(Edge(v,d));
        g[v].push_back(Edge(u,d));
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d%d%d",&c,&s,&ee);
        int ans = bfs();
        if(ans==-1) printf("impossible\n");
        else printf("%d\n",ans);
    }
    
    return 0;
}
