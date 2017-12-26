#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
typedef pair<int,int> PII;
int k;
int n,m;
char labyrinth[1000][1010];
PII start;
int dist[1000][1000];
int bfs(PII s){
    queue<PII> Q;
    memset(dist,-1,sizeof dist);
    dist[s.first][s.second] = 0;
    Q.push(s);
    int ans = -1;
    while(!Q.empty()){
        PII head = Q.front();
        Q.pop();
        int x = head.first, y = head.second;
        int d = dist[x][y];
        if(d>ans) ans = d, start = make_pair(x,y);
        int nx,ny;
        for(int dx=-1;dx<=1;dx++)
            for(int dy=-1;dy<=1;dy++)
                if((dx==0)^(dy==0)){
                nx = x+dx, ny = y+dy;
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(labyrinth[nx][ny]!='.') continue;
                if(dist[nx][ny]!=-1) continue;
                dist[nx][ny] = d+1;
                Q.push(make_pair(nx,ny));
            }
    }
    return ans;
}
int main()
{
    scanf("%d",&k);
    while(k--){
        scanf("%d%d",&m,&n);
        for(int i=0;i<n;i++)
            scanf("%s",labyrinth[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(labyrinth[i][j]=='.') start = make_pair(i,j);
        bfs(start);
        printf("Maximum rope length is %d.\n",bfs(start));
        
    }
    return 0;
}
