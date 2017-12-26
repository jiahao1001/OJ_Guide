#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
using namespace std;
const int N = 1010;
int g[N][N];
int cnt, dfn[N],low[N], instack[N];
int in[N], out[N];
int scc[N];
int s_cnt;
stack<int> S;
int n,m;
void dfs(int u){
    dfn[u]=low[u]= cnt++;
    instack[u]=1;
    S.push(u);
    for(int v=1;v<=n;v++)
        if(g[u][v]){
            if(dfn[v]<0){
                dfs(v);
                low[u] = min(low[u],low[v]);
            }else if(instack[v]){
                low[u] = min(low[u],dfn[v]);
            }
        }
    
    if(dfn[u]==low[u]){
        int id=s_cnt++;
        //cout<<"er"<<endl;
        int v;
        do{
            v = S.top();
            instack[v]=0;
            scc[v] = id;
            S.pop();
        }while(v!=u);
        
    }
    
}
int main(){
    int T;
    int u,v;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(g,0,sizeof(g));
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            g[u][v] = 1;
        }
        s_cnt = 0;
        cnt = 0;
        memset(dfn,-1,sizeof(dfn));
        memset(low,-1,sizeof(low));
        memset(scc,-1,sizeof(scc));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(instack,0,sizeof(instack));
        for(int i=1;i<=n;i++)
            if(dfn[i]<0) dfs(i);
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(g[i][j] && scc[i]!=scc[j]) in[scc[j]]++,out[scc[i]]++;
            }
        int out_z=0, in_z=0;
        for(int i=0;i<s_cnt;i++)
            if(!in[i]) in_z++;
            else if(!out[i]) out_z++;
         
        if(in_z<=1 && out_z<=1) printf("Yes\n");
        else printf("No\n");
    }
}
