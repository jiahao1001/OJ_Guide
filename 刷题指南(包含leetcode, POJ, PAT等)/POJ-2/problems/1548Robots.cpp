
#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
typedef pair<int,int>  pi;
const int N = 24*24;
pi garbage[N];
int g[N][N];
int ly[N],vis[N];
int n;
bool dfs(int u){
    for(int v=0;v<n;v++){
        if(!g[u][v] || vis[v]) continue;
        vis[v] = 1;
        if(ly[v]==-1 || dfs(ly[v])){
            ly[v] = u;
            return true;
        }
    }
    return false;
}
int max_match(){
    int cnt = 0;
    memset(ly,-1,sizeof ly);
    for(int i=0;i<n;i++){
        memset(vis, 0, sizeof vis);
        if(dfs(i)) cnt++;
    }
    return cnt;
}
int main(){
    int x,y;
    while(scanf("%d%d",&x,&y),x!=-1 && y!=-1){
        if(x+y==0){
            printf("0\n");
            continue;
        }
        n = 0;
        garbage[n++] = make_pair(x, y);
        while(scanf("%d%d",&x,&y),x||y){
            garbage[n++] = make_pair(x, y);
        }
        memset(g,0,sizeof g);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(garbage[i].first<=garbage[j].first && garbage[i].second<=garbage[j].second)
                    g[i][j] = 1;
        
        printf("%d\n",n-max_match());
    }
    return 0;
}
