#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string.h>
#include<stack>
using namespace std;
const int N  = 1600;

int n,m;
int k;
char mine[50][50];
int magic[N];
int g[N][N];
int ore[N];
int scc[N],s_cnt,cnt,dfn[N],low[N];
int s_g[N][N],s_ore[N];
int dp[N];
stack<int> S;
int x,y;
void dfs(int u){
    S.push(u);
    dfn[u]=low[u]=cnt++;
    for(int v=0;v<n*m;v++)
        if(g[u][v]){
            if(dfn[v]==-1){
                dfs(v);
                low[u] = min(low[u],low[v]);
            }else low[u]=min(low[u],dfn[v]);
        }
    if(dfn[u]==low[u]){
        int v, id = s_cnt++;
        s_ore[id] = 0;
        do{
            v = S.top();
            S.pop();
            s_ore[id]+=ore[v];
            scc[v] = id;
            dfn[v] = n*m;
        }while(v!=u);
    }
    
}
int f(int u){
    if(dp[u]!=-1) return dp[u];
    dp[u] = 0;
    for(int i=0;i<s_cnt;i++)
        if(s_g[u][i]) dp[u] = max(dp[u],f(i));
    dp[u]+=s_ore[u];
    return dp[u];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        k = 0;
        memset(g,0,sizeof(g));
        memset(ore,0,sizeof(ore));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%s",mine[i]);
            for(int j=0;j<m;j++) 
                if(mine[i][j]=='*') magic[k++]=i*m+j;
                else if(mine[i][j]!='#') ore[i*m+j] = mine[i][j]-'0';
        }
        for(int i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            //if(mine[x][y]=='#') continue;
            g[magic[i]][x*m+y]=1;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(mine[i][j]=='#') continue;
                if(j+1<m && mine[i][j+1]!='#') g[i*m+j][i*m+j+1]=1;
                if(i+1<n && mine[i+1][j]!='#') g[i*m+j][i*m+m+j]=1;
            }
        memset(scc,-1,sizeof(scc));
        s_cnt = 0;
        cnt = 0;
        memset(dfn,-1,sizeof(dfn));
        memset(low,-1,sizeof(low));
        for(int i=0;i<n*m;i++)
            if(dfn[i]<0) dfs(i);
        memset(s_g,0,sizeof(s_g));
        for(int i=0;i<n*m;i++)
            for(int j=0;j<n*m;j++)
                if(g[i][j] && scc[i]!=scc[j]) s_g[scc[i]][scc[j]] = 1;
           
        memset(dp,-1,sizeof(dp));
        printf("%d\n",f(scc[0]));
        
    }
    return 0;
}
