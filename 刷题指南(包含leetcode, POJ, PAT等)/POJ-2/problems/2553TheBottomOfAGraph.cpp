
#include <iostream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;
const int V = 5010;
int instack[V];
vector<int> g[V];
int degree[V];
int scc[V];
int s_cnt;
int n,m;
int dfn[V],low[V];
int cnt;
stack<int> S;
void dfs(int u){
    dfn[u] = low[u] = cnt++;
    S.push(u);
    instack[u] = 1;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(dfn[v]<0){
            dfs(v);
            low[u] = min(low[u],low[v]);
            
        }else if(instack[v]){
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        int id = s_cnt++;
        //printf("-----%d\n",id);
        int v;
        do{
            v = S.top();
            S.pop();
            instack[v] = 0;
            scc[v]=id;
          //  printf("%d\n",v);
        }while(v!=u);
    }
    
    
}
int main(){
    while(scanf("%d",&n),n){
        scanf("%d",&m);
        for(int i=1;i<=n;i++)
            g[i].clear();
        int u,v;
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
        }
        memset(degree,0,sizeof(degree));//out degree
        s_cnt = 0;
        memset(scc,-1,sizeof(scc));
        memset(dfn,-1,sizeof(dfn));
        memset(low,-1,sizeof(low));
        cnt = 0;
        for(int i=1;i<=n;i++){
            if(dfn[i]<0) dfs(i);
        }
        for(int i=1;i<=n;i++)
            for(int j=0;j<g[i].size();j++){
                u = i, v = g[i][j];
                if(scc[u]!=scc[v]) degree[scc[u]]++;
            }
        
       // printf("====in block\n");
        set<int> block;
        for(int i=0;i<s_cnt;i++)
            if(!degree[i]) {
         //       cout<<i<<endl;
            block.insert(i);
            }
        
        int first = 1;
        vector<int> result;
        for(int i=1;i<=n;i++)
            if(block.count(scc[i])){
                if(first){
                    first = 0;
                    printf("%d",i);
                }
                else printf(" %d",i);
            }
        printf("\n");
    }
    return 0;
}
