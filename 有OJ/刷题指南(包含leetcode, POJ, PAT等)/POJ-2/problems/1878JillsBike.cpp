#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int,int> pi;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int height[25][25];
int road[4][25][25];
int n,m;
pi src, gl;
pi ppp[25][25];
int v[25][25];
void print_no(int x,int y){
    printf("To get from %d-%d to %d-%d, stay put!\n",x,y,x,y);
}
bool bfs(){
    memset(v,0,sizeof v);
    int xx,y1,x2,yy;
    xx=src.first, y1=src.second;
    v[xx][y1] = 1;
    queue<pi> q;
    q.push(make_pair(xx,y1));
    while(!q.empty()){
        pi h = q.front();
        q.pop();
        if(h==gl) return true;
        xx = h.first, y1 = h.second;
        for(int k=0;k<4;k++){
            if(!road[k][xx][y1]) continue;
            x2 = xx+dx[k], yy=y1+dy[k];
            if(x2<=0 || x2>n || yy<=0 || yy>m) continue;
            if(height[x2][yy]-height[xx][y1]>10) continue;
            if(v[x2][yy]) continue;
            v[x2][yy] = 1;
            ppp[x2][yy] = h;
            q.push(make_pair(x2,yy));
        }
    }
    return false;
}
void print(int x,int y){
    if(make_pair(x,y)!=src){
        pi h = ppp[x][y];
        print(h.first,h.second);
    }
    cout<<x<<"-"<<y;
    if(make_pair(x,y)==gl)cout<<endl;
    else cout<<" to ";
}
int main()
{
    int xx,y1,x2,yy;
    bool bg = true;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&height[i][j]);
        memset(road,0,sizeof road);
        while(scanf("%d%d%d%d",&xx,&y1,&x2,&yy),xx){
            if(!xx) break;
            if(xx==x2){
                if(y1<yy){
                    for(int y=y1;y<yy;y++)
                        road[1][xx][y] = 1;
                }else{
                    for(int y=y1;y>yy;y--)
                        road[3][xx][y] = 1;
                }
            }else{
                if(xx<x2){
                    for(int x=xx;x<x2;x++)
                        road[2][x][y1] = 1;
                }else{
                    for(int x=xx;x>x2;x--)
                        road[0][x][y1] = 1;
                }
            }
        }
        while(scanf("%d%d%d%d",&xx,&y1,&x2,&yy)){
            if(!xx) break;
            if(bg) bg = false;
            else printf("\n");
            if(xx==x2 && y1==yy){
                print_no(xx,yy);
            }

            else{
                src.first = xx, src.second = y1;
                gl.first = x2, gl.second = yy;
                if(!bfs()){
                    printf("There is no acceptable route from");
                    cout<<xx<<"-"<<y1<<" to "<<x2<<"-"<<yy<<"."<<endl;
                }

                else
                    print(x2,yy);
            }
        }
    }
    return 0;
}
