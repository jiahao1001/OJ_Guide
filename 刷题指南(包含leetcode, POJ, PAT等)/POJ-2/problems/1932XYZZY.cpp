#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
#include<set>
using namespace std;
int n;
int e[101],cnt,v;
vector<int> adj[101];
int d[101];
int reach[101][101];
bool bell(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(reach[i][k] && reach[k][j]) reach[i][j] = 1;
    fill(d,d+101,INT_MIN/2);
    d[1] = 100;
    int tot=0;
    for(int i=1;i<=n;i++){
        bool flag = 0;
        for(int j=1;j<=n;j++)
            for(int k=0;k<adj[j].size();k++){
                if(d[j]<=0) continue;
                v=adj[j][k];
                if(!reach[1][v] || !reach[v][n])continue;
                int w = e[v];
                if(d[j]+w>d[v]) d[v] = d[j]+w, flag=1;
            }
        if(flag) tot++;
        else break;
    }
    //for(int i=1;i<=n;i++) printf("%d ",d[i]);
    //printf("\n");
    if(d[n]>0 || tot>=n) return true;
    return false;
    
}
int main(){
    while(scanf("%d",&n),n!=-1){
        memset(reach,0,sizeof reach);
        for(int i=1;i<=n;i++){
            reach[i][i] = 1;
            scanf("%d",e+i);
            adj[i].clear();
            scanf("%d",&cnt);
            while(cnt--){
                scanf("%d",&v);
                reach[i][v] = 1;
                adj[i].push_back(v);
            }
        }
        if(bell())printf("winnable\n");
        else printf("hopeless\n");
    }
    return 0;
}
