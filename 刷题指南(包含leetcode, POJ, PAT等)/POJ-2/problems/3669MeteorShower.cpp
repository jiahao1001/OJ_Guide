#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int vis[305][305];
int destroy[305][305];
int M,x,y,t;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
struct Cow{
    int x,y,t;
};
int bfs()
{
    Cow cow;
    Cow ncow;
    cow.x=0,cow.y=0,cow.t=0;
    queue<Cow> cow_queue;
    if(destroy[0][0]>cow.t) cow_queue.push(cow),vis[cow.x][cow.y]=1;
    while(!cow_queue.empty())
    {
        cow=cow_queue.front();
        cow_queue.pop();
        if(destroy[cow.x][cow.y]==2000) return cow.t;
        for(int k=0;k<4;k++){
            ncow.x=cow.x+dx[k];
            ncow.y=cow.y+dy[k];
            ncow.t=cow.t+1;
            if(ncow.x>=0 && ncow.y>=0 &&!vis[ncow.x][ncow.y]&& ncow.t<destroy[ncow.x][ncow.y])
                cow_queue.push(ncow),vis[ncow.x][ncow.y]=1;
        }
    }
    
    return -1;
}
int main()
{
    scanf("%d",&M);
    for(int i=0;i<305;i++)
        for(int j=0;j<305;j++)
            destroy[i][j]=2000;
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&x,&y,&t);
        destroy[x][y]=min(destroy[x][y],t);
        for(int k=0;k<4;k++){
            if(x+dx[k]>=0 && y+dy[k]>=0)
                destroy[x+dx[k]][y+dy[k]]=min(destroy[x+dx[k]][y+dy[k]],t);
        }
    }
    printf("%d\n",bfs());
    return 0;
}
