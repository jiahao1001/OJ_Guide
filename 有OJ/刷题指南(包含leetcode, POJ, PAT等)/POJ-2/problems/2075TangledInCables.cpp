#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<string>
#include<utility>
#include<map>
using namespace std;
const int INF = INT_MAX/2;
double len;
int n,m;
string town,u,v;
map<string,int> id;
double w;
int main()
{
    cin>>len;
    cin>>n;
    vector<vector<double> > g(n+1,vector<double>(n+1,INF));
    for(int i=1;i<=n;i++)
        cin>>town, id[town] = i;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        int a = id[u], b = id[v];
        g[a][b] = g[b][a] = w;
    }
    //prim
    vector<double> dist(n+1,1.0*INF);
    vector<int> visited(n+1,0);
    dist[1] = 0;
    double total = 0;
    for(int k=1;k<=n;k++){
        double best = INF;
        int id = 0;
        for(int i=1;i<=n;i++)
            if(!visited[i] && dist[i]<=best) best = dist[i], id = i;
        total += dist[id];
        visited[id] = 1;
        for(int i=1;i<=n;i++)
            if(!visited[i] && g[id][i]<dist[i]) dist[i] = g[id][i];
    }
    if(total<=len) printf("Need %.1f miles of cable\n",total);
    else printf("Not enough cable\n");
    
    return 0;
}
