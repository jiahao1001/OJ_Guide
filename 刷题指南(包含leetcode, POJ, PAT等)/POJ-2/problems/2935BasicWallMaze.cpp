
#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int,int> PI;
int sx,sy,ex,ey;

pair<int,int> pre[7][7]; //(0,0) unvisited
char dir[7][7];
char vwall[7][7];
char hwall[7][7];
void dfs(int x,int y){
    if(x==sx && y==sy) return;
    PI p = pre[x][y];
    dfs(p.first,p.second);
    printf("%c",dir[x][y]);
}
int main(){
    while(cin>>sx>>sy, sx|| sy){
        cin>>ex>>ey;
        int x1,y1,x2,y2;
        memset(vwall,'.',sizeof(vwall));
        memset(hwall,'.',sizeof(hwall));
        for(int i=0;i<7;i++)
            for(int j=0;j<7;j++) pre[i][j] = make_pair(0,0);
        PI P0 = make_pair(0, 0);
        for(int i=0;i<3;i++){
            cin>>x1>>y1>>x2>>y2;
            if(x1==x2){
                for(int y=y1+1;y<=y2;y++) vwall[x1][y] = '*';
            }else{
                for(int x=x1+1;x<=x2;x++) hwall[x][y1] ='*';
            }
        }
        queue<pair<int,int> > Q;
        Q.push(make_pair(sx, sy));
        pre[sx][sy] = make_pair(1, 1);
        while(!Q.empty()){
            PI h = Q.front();
            Q.pop();
            if(h==make_pair(ex, ey)){
                break;
            }
            int x = h.first, y = h.second;
            //N
            if(y>1 && hwall[x][y-1]=='.'&&pre[x][y-1]==P0){
                pre[x][y-1] = h;
                dir[x][y-1] = 'N';
                Q.push(make_pair(x, y-1));
            }
            //E
            if(x<6 && vwall[x][y]=='.' && pre[x+1][y]==P0){
                pre[x+1][y] = h;
                dir[x+1][y] = 'E';
                Q.push(make_pair(x+1, y));
            }
            //S
            if(y<6 && hwall[x][y]=='.' && pre[x][y+1]==P0){
                pre[x][y+1]=h;
                dir[x][y+1] = 'S';
                Q.push(make_pair(x, y+1));
            }
            //W
            if(x>1 && vwall[x-1][y]=='.' && pre[x-1][y]==P0){
                pre[x-1][y] = h;
                dir[x-1][y] = 'W';
                Q.push(make_pair(x-1, y));
            }
        }
        dfs(ex,ey);
        printf("\n");
    }
    return 0;
}
