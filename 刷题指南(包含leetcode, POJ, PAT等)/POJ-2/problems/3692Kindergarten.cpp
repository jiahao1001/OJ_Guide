#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int g[205][205];
int G,B,M;
int vis[205],ly[205];
bool dfs(int i){
    for(int j=1;j<=B;j++)
        if(!vis[j] && g[i][j]){
            vis[j] = 1;
            if(ly[j]==-1 || dfs(ly[j])){
                ly[j] = i;
                return true;
            }
        }
    return false;
}
int max_match(){
    int mat = 0;
    memset(ly,-1,sizeof(ly));
    for(int i=1;i<=G;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) mat++;
    }
    return mat;
}
int main()
{
    int q=1;
    while(scanf("%d%d%d",&G,&B,&M),G||B||M)
    {
        for(int i=1;i<=G;i++)
            for(int j=1;j<=B;j++) g[i][j] = 1;
        int x,y;
        for(int i=0;i<M;i++){
            scanf("%d%d",&x,&y);
            g[x][y] = 0;
        }
        printf("Case %d: %d\n",q++,G+B-max_match());
    }
    
    return 0;
}
