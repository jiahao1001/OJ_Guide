#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int t;
int i1,j1,i2,j2;
int g[40][40];
int bad[9][9];
int ly[40];
int vis[40];
bool dfs(int i){
    for(int j=1;j<=32;j++)
        if(g[i][j] && !vis[j]){
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
    memset(ly,-1,sizeof ly);
    for(int i=1;i<=32;i++){
        memset(vis,0,sizeof vis);
        if(dfs(i)) mat++;
    }
    return mat;
}
int main()
{
    scanf("%d",&t);
    int q=1;
    while(t--){
        scanf("%d%d%d%d",&i1,&j1,&i2,&j2);
        memset(bad,0,sizeof bad);
        bad[i1][j1] = bad[i2][j2] = 1;
        //white  (i%2)^(j%2)
        memset(g,0,sizeof(g));
        for(int i=1;i<=8;i++)
            for(int j=1;j<=8;j++)
                if((i%2)^(j%2)){
                    if(bad[i][j]) continue;
                    for(int k=0;k<4;k++){
                        int x = i+dx[k], y = j+dy[k];
                        if(x<1 || x>8 || y<1 || y>8) continue;
                        if(bad[x][y]) continue;
                        g[(i-1)*4+(j+1)/2][(x-1)*4+(y+1)/2] = 1;
                    }
                }
        
        printf("Scenario #%d:\n",q++);
        if(max_match()==31) printf("1\n\n");
        else printf("0\n\n");
    }
    return 0;
}
