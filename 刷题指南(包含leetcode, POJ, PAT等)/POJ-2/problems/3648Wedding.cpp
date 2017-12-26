#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int N = 1001;
vector<int> g[2*N];
int n,m;
char s1[10],s2[10];
int g2[2*N][2*N];
int oppo[2*N];
int color[2*N];
int dfn[2*N],low[2*N],scc[2*N],s_cnt,cnt;
stack<int> S;

inline char flip(char c){
    if(c=='h') return 'w';
    if(c=='w') return 'h';
    return ' ';
}
void addedge(int a,int b,char c1,char c2){
    if(c1=='w') a=2*a;
    else a=2*a+1;
    if(c2=='w') b=2*b;
    else b=2*b+1;
    g[a].push_back(b);
}
void dfs(int u){
    S.push(u);
    dfn[u] = low[u] = cnt++;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(dfn[v]==-1){
            dfs(v);
            low[u] = min(low[u],low[v]);
        }else low[u] = min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        int id = s_cnt++;
        int v;
        do{
            v = S.top();
            S.pop();
            scc[v] = id;
            dfn[v] = 2*n;
        }while(u!=v);
    }
    
}
void tarjan(){
    memset(dfn,-1,sizeof(dfn));
    memset(low,-1,sizeof(low));
    s_cnt = 0;
    cnt = 0;
    memset(scc,-1,sizeof(scc));
    for(int i=0;i<2*n;i++)
        if(dfn[i]==-1) dfs(i);
}
int vis[2*N];
void dfs1(int i){
    vis[i] = 1;
    for(int j=0;j<s_cnt;j++)
        if(g2[i][j] && !vis[j]){
            dfs1(j);
        }
    if(!color[i]){
        color[i] = 1;
        color[oppo[i]] = -1;
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m){
        for(int i=0;i<2*n;i++) g[i].clear();
        g[0].push_back(1);
        for(int i=0;i<m;i++){
            scanf("%s%s",s1,s2);
            int len1 = strlen(s1),len2 = strlen(s2);
            char c1 = s1[len1-1],c2 = s2[len2-1];
            s1[len1]=0,s2[len2]=0;
            int a = atoi(s1),b=atoi(s2);
            addedge(a,b,c1,flip(c2));
            addedge(b,a,c2,flip(c1));
        }
        tarjan();
        bool bad = false;
        for(int i=0;i<n;i++){
            if(scc[2*i]==scc[2*i+1]) bad = true;
        }
        if(bad) {
            printf("bad luck\n");
            continue;
        }
        memset(g2,0,sizeof(g2));
        for(int i=0;i<2*n;i++){
            for(int j=0;j<g[i].size();j++){
                int v = g[i][j];
                if(scc[i]!=scc[v]) g2[scc[i]][scc[v]] = 1;
            }
        }
        for(int i=0;i<n;i++){
            oppo[scc[2*i]]=scc[2*i+1];
            oppo[scc[2*i+1]] = scc[2*i];
        }
        //toposort
        memset(color,0,sizeof(color));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<s_cnt;i++)
            if(!vis[i]) dfs1(i);
        for(int i=1;i<n;i++){
            if(i==1)printf("1");
            else printf(" %d",i);
            if(color[scc[2*i]]==-1) printf("w");
            else printf("h");
        }
        printf("\n");
    }
    return 0;
}
