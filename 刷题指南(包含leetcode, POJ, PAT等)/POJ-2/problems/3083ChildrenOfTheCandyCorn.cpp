
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int w,h;
int sx,sy;
int dir;
char maze[45][45];
int dist[45][45];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void init(){
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            if(maze[i][j]=='S') {
                sx=i,sy=j;
            }
        }
    if(sx==h-1) dir=0;
    else if(sx==0) dir=2;
    else if(sy==0) dir=1;
    else if(sy==w-1) dir=3;
}
void calc(){
    int cnt = 1;
    int left = 0;
    int x,y;
    while(maze[sx][sy]!='E'){
        left = (dir+3)%4;
        x = sx+dx[left], y = sy+dy[left];
        //turn left
        if(maze[x][y]!='#'){
            cnt++;
            sx = x, sy = y;
            dir = left;
            continue;
        }
        x= sx+dx[dir], y = sy+dy[dir];
        if(maze[x][y]!='#'){
            cnt++;
            sx = x, sy = y;
            continue;
        }
        dir = (dir+1)%4;
    }
    printf("%d ",cnt);
}
void bfs(){
    //print the shortest path from S to E
    init();
    dist[sx][sy] = 1;
    queue<int> Q;
    Q.push(sx*w+sy);
    int x,y;
    while(!Q.empty()){
        int head = Q.front();
        Q.pop();
        x = head/w, y = head%w;
        if(maze[x][y]=='E'){
            printf("%d\n",dist[x][y]);
            return;
        }
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx>=0 && nx<h && ny>=0 && ny<w && maze[nx][ny]!='#'){
                if(!dist[nx][ny]){
                    dist[nx][ny] = dist[x][y]+1;
                    Q.push(nx*w+ny);
                }
            }
        }
        
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&w,&h);
        for(int i=0;i<h;i++)
            scanf("%s",maze[i]);
        init();
        calc();
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                if(maze[i][j]=='E') maze[i][j]='S';
                else if(maze[i][j]=='S') maze[i][j]='E';
        init();
        calc();
        memset(dist,0,sizeof(dist));
        bfs();
    }
    return 0;
}
