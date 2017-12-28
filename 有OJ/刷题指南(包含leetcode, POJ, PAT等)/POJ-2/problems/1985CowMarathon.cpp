#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
const int N = 40001;
int n,m;
vector<pii> g[N];
int start;
int dist[N];
int bfs(){
    memset(dist,-1,sizeof dist);
    dist[start] = 0;
    queue<int> Q;
    Q.push(start);
    int ans = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        int d = dist[u];
        if(dist[u]>ans) ans = dist[u], start = u;
        for(int i=0;i<g[u].size();i++){
            pii e = g[u][i];
            if(dist[e.first]!=-1) continue;
            dist[e.first] = d + e.second;
            Q.push(e.first);
        }
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    char c;
    int u,v,w;
    for(int i=0;i<m;i++){
        scanf("%d%d%d %c",&u,&v,&w,&c);
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    start = 1;
    bfs();
    printf("%d\n",bfs());
    return 0;
}
