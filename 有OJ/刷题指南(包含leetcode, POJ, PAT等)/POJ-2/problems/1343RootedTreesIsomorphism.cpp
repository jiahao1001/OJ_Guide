#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
const int N = 120;
int n,k;
vector<int> g[N];
int is_root[N];
string h[160];
string dfs(int u){
    string s = "1";
    vector<string> vs;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        vs.push_back(dfs(v));
    }
    sort(vs.begin(),vs.end());
    for(int i=0;i<vs.size();i++)
        s+=vs[i];
    return s+"0";
}
int vis[160];
void print(string s){
    for(int i=1;i<=k;i++)
        if(!vis[i] && h[i]==s){
            vis[i] = 1;
            printf(" = %d",i);
        }
}
int main()
{
    int u,v;
    scanf("%d%d",&k,&n);
    for(int t=1;t<=k;t++){
        for(int i=1;i<=n;i++) g[i].clear(),is_root[i] = 1;
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            is_root[v] = 0;
        }
        int root = 0;
        for(int i=1;i<=n;i++) if(is_root[i]) root=i;
        h[t] = dfs(root);
    }
    for(int i=1;i<=k;i++)
        if(!vis[i]){
            vis[i] = 1;
            printf("%d",i);
            print(h[i]);
            printf(" ;\n");
        }
    
    return 0;
}
