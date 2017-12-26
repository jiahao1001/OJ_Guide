#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
using namespace std;
char board[20][25];
int R,C;
int vis[26];
int best = 0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int i,int j,int d)
{
    int	x,y;
    for(int k=0;k<4;k++){
     	x = i+dx[k], y=j+dy[k];
        if(x<0 || x>=R || y<0 || y>=C) continue;
        int ix = board[x][y]-'A';
        if(!vis[ix]){
            vis[ix] = 1;
            dfs(x,y,d+1);
            vis[ix] = 0;
        }
    }
    best = max(best,d);
}

int main()
{
    scanf("%d%d",&R,&C);
    for(int i=0;i<R;i++)
        scanf("%s",board[i]);
    vis[board[0][0]-'A'] = 1;
    dfs(0,0,1);
    printf("%d\n",best);
}
