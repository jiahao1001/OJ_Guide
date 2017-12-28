#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<map>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
int g[100][100];
int wall[4][100][100];
int w,h,m;
char path[10010];
vector<PII> A,B;
int dist[2][100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
PII goal;
int pathlen;
map<char,int> dirs;
int vis[100][100];
bool walk(){
    //the seqence doesn't cross wall
    int x=0,y=0;
    vis[x][y] = 1;
    int len = strlen(path);
    for(int i=0;i<len;i++){
        int k = dirs[path[i]];
        if(wall[k][x][y]) return false;
        x+=dx[k],y+=dy[k];
        vis[x][y] = 1;
        //printf("(%d,%d)\n",x,y);
    }
    goal = make_pair(x,y);
    return true;
}
void bfs(int x,int y,int c){
    dist[c][x][y] = 0;
    int xx,yy;
    queue<PII> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        PII hd = q.front();
        q.pop();
        x = hd.first, y = hd.second;
        int d = dist[c][x][y];
        for(int k=0;k<4;k++){
            if(wall[k][x][y]) continue;
            xx=x+dx[k],yy=y+dy[k];
            if(xx<0 || xx>=w || yy<0 || yy>=h) continue;
            if(dist[c][xx][yy]!=-1) continue;
            dist[c][xx][yy] = d+1;
            q.push(make_pair(xx,yy));
        }
    }
}
void compute_dist(){
    bfs(0,0,0);
    bfs(goal.first,goal.second,1);
}
bool check_unique_shortest(){
    for(int x=0;x<w;x++)
        for(int y=0;y<h;y++){
            if(dist[0][x][y]==-1 || dist[1][x][y]==-1) return false;
            if(!vis[x][y] && dist[0][x][y]+dist[1][x][y]==dist[1][0][0]) return false;
        }
    return true;
}
bool chech_wall(){
    int n = A.size();
    int x1,y1,x2,y2;
    for(int i=0;i<n;i++){
        x1=A[i].first,y1=A[i].second;
        x2=B[i].first,y2=B[i].second;
        if(dist[0][x1][y1]+dist[1][x2][y2]>=pathlen && dist[0][x2][y2]+dist[1][x1][y1]>=pathlen) return false;
    }
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    int x1,y1,x2,y2;
    dirs['U'] = 0;
    dirs['R'] = 1;
    dirs['D'] = 2;
    dirs['L'] = 3;
    while(t--){
        scanf("%d%d",&w,&h);
        scanf("%s",path);
        scanf("%d",&m);
        pathlen = strlen(path);
        memset(vis,0,sizeof vis);
        memset(dist,-1,sizeof dist);
        memset(g,0,sizeof g);
        memset(wall,0,sizeof wall);
        A.clear(), B.clear();
        for(int i=0;i<m;i++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1==x2){
                //horiz
                if(y1>y2) swap(y1,y2);
                wall[0][x1][y1] = 1;
                wall[2][x1][y2] = 1;
            }else{
                //ver
                if(x1>x2) swap(x1,x2);
                wall[1][x1][y1] = 1;
                wall[3][x2][y1] = 1;
            }
            A.push_back(make_pair(x1,y1));
            B.push_back(make_pair(x2,y2));
        }
        if(!walk()){
            printf("INCORRECT\n");
            continue;
        }
        compute_dist();
        if(strlen(path)!=dist[1][0][0] || !check_unique_shortest()){
            printf("INCORRECT\n");
            continue;
        }
        if(chech_wall()) printf("CORRECT\n");
        else printf("INCORRECT\n");
    }
    return 0;
}
