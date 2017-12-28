#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
#include<float.h>
#include<math.h>
using namespace std;
int n,m,p;
int board[35][35];
int g[1024][1024];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int vis[1024],ly[1024];
int white,black;
bool dfs(int i){
    for(int j=0;j<black;j++)
        if(g[i][j]&&!vis[j]){
            vis[j] = 1;
            if(ly[j]==-1||dfs(ly[j])){
                ly[j] = i;
                return true;
            }
        }
    return false;
}
int max_match(){
    int mat = 0;
    for(int i=0;i<white;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) mat++;
    }
    return mat;
}
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    int x,y;
    memset(board,0,sizeof(board));
    memset(g,0,sizeof(g));
    memset(vis,0,sizeof(vis));
    memset(ly,-1,sizeof(ly));
    for(int i=0;i<p;i++)
    {
        scanf("%d%d",&x,&y);
        board[y][x] = -1;
    }
    white = 0, black = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!board[i][j]){
                if((i+j)%2) board[i][j]=white++;
                else board[i][j]=black++;
            }
    if(white!=black){
        printf("NO\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(board[i][j]==-1) continue;
            if((i+j)%2==0) continue; 
            //white to black
            for(int k=0;k<4;k++){
                x = i+dx[k], y = j+dy[k];
                if(x<=0 || x>n || y<=0 || y>m || board[x][y]==-1) continue;
                g[board[i][j]][board[x][y]] = 1;
            }
        }
    
    if(max_match()==white) printf("YES\n");
    else printf("NO\n");
    return 0;
}
