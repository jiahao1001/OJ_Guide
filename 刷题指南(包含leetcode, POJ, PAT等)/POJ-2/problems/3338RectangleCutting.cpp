#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<set>
#include<string.h>
#include<queue>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;
int W,H;
int v[21][21];
int h[21][21];
int vis[21][21];
void cut(int x1,int y1,int x2,int y2){
    for(int i=x1+1;i<=x2;i++)
        h[y1][i] = h[y2][i] = 1;
    for(int i=y1+1;i<=y2;i++)
        v[x1][i] = v[x2][i] = 1;
}
void dfs(int x,int y){
    vis[x][y] = 1;
    //up
    if(!h[y][x] && !vis[x][y+1]) dfs(x,y+1);
    //right
    if(!v[x][y] && !vis[x+1][y]) dfs(x+1,y);
    //down
    if(!h[y-1][x]&& !vis[x][y-1]) dfs(x,y-1);
    //left
    if(!v[x-1][y]&& !vis[x-1][y]) dfs(x-1,y);
}
int main(){
    int n,x1,y1,x2,y2;
    while(scanf("%d%d",&W,&H),H||W){
        scanf("%d",&n);
        memset(v,0,sizeof v);
        memset(h,0,sizeof h);
        memset(vis,0,sizeof vis);
        cut(0,0,H,W);
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1>x2) swap(x1,x2);
            if(y1>y2) swap(y1,y2);
            cut(x1,y1,x2,y2);
        }
        int cnt = 0;
        for(int i=1;i<=H;i++)
            for(int j=1;j<=W;j++)
                if(!vis[i][j]){
                    cnt++;
                    dfs(i,j);
                }
        printf("%d\n",cnt);
    }
    return 0;
}
