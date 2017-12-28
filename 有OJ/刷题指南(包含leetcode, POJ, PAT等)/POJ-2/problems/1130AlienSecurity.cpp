#include<queue>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int n,e;
vector<vector<int> > g;
vector<vector<int> > rg;
vector<int> dist;
vector<int> vis;
void dfs(int u){
    if(vis[u]) return;
    vis[u] = 1;
    for(int i=0;i<g[u].size();i++)
        dfs(g[u][i]);
}
bool check(int i){
    //put gurad in room i
    vis = vector<int>(n,0);
    vis[i] = 1;
    dfs(0);
    return !vis[e];
}
int bfs(){
    dist = vector<int>(n,-1);
    dist[e] = 0;
    queue<int> q;
    q.push(e);
    while(!q.empty()){
        int h = q.front();
        q.pop();
        int d = dist[h];
        if(d && check(h)) return h;
        for(int i=0;i<rg[h].size();i++){
            int b = rg[h][i];
            if(dist[b]!=-1) continue;
            dist[b] = d+1;
            q.push(b);
        }
    }
    return -1;
}
int main()
{
    cin>>n>>e;
    g = vector<vector<int> >(n,vector<int>());
    rg = vector<vector<int> >(n,vector<int>());
    vis = vector<int>(n,0);
    int a,b;
    while(cin>>a>>b)
        g[a].push_back(b), rg[b].push_back(a);
    
    cout<<"Put guards in room "<<bfs()<<"."<<endl;
    return 0;
}
