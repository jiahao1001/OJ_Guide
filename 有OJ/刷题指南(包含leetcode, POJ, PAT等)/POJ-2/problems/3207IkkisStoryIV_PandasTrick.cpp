#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string.h>
#include<stack>
#include<set>
#include<string>
#include<limits.h>
#include<algorithm>
#include<float.h>
using namespace std;
const int N = 1000;
int a[500],b[500],n,m;
int g[N][N];
int dfn[N],low[N],s_cnt,cnt,scc[N];
stack<int> S;
bool cross(int a1,int b1,int a2,int b2){
    if(a1>b1) swap(a1,b1);
    if(a2>b2) swap(a2,b2);
    return (a2<a1 && b2>a1 && b2<b1) || (a2>a1 && a2<b1 && b2>b1);
}
void dfs(int u){
    dfn[u] = low[u] = cnt++;
    S.push(u);
    for(int i=0;i<n;i++)
        if(g[u][i]){
            if(dfn[i]==-1){
                dfs(i);
                low[u] = min(low[u],low[i]);
            }
            else low[u] = min(low[u],dfn[i]);
        }
    if(low[u]==dfn[u]){
        int id = s_cnt++;
        int v;
        do{
            v = S.top();
            S.pop();
            scc[v] = id;
            dfn[v] = n;
            
        }while(u!=v);
    }
}
int main(){
    memset(g,0,sizeof(g));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d",a+i,b+i);
    for(int i=0;i<m;i++)
        for(int j=i+1;j<m;j++)
            if(cross(a[i],b[i],a[j],b[j])) g[i][m+j] = g[m+i][j] =g[j+m][i] = g[j][i+m]= 1;
    
        memset(dfn,-1,sizeof(dfn));
        memset(low,-1,sizeof(low));
        memset(scc,-1,sizeof(scc));
        s_cnt = 0;
        cnt = 0;
        n = 2*m;
        for(int i=0;i<n;i++)
            if(dfn[i]==-1) dfs(i);
        
        for(int i=0;i<m;i++)
            if(scc[i]==scc[i+m]){
                printf("the evil panda is lying again\n");
                return 0;
                
            }
        
        printf("panda is telling the truth...\n");
        return 0;
        
}
