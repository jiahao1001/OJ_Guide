#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
const int N = 2500;
char maze[60][60];
int n,m;
int t;
int id[N];
int g[105][105];
int dist[60][60];
int cnt;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
typedef pair<int,int> PII;
inline void bfs(int i,int j){
    int x,y,nx,ny;
    memset(dist,-1,sizeof(dist));
    dist[i][j] = 0;
    g[id[i*m+j]][id[i*m+j]] = 0;
    queue<PII> Q;
    Q.push(make_pair(i,j));
    
    while(!Q.empty()){
        PII head = Q.front();
        Q.pop();
        
        x = head.first, y = head.second;
        int d = dist[x][y];
        for(int k=0;k<4;k++){
            nx = x+dx[k], ny = y+dy[k];
            if(maze[nx][ny]=='#') continue;
            if(dist[nx][ny]!=-1) continue;
            dist[nx][ny] = d+1;
            if(maze[nx][ny]=='S' || maze[nx][ny]=='A')
                g[id[i*m+j]][id[nx*m+ny]] = d+1;
            Q.push(make_pair(nx,ny));
        }
    }
    
}
int vis[105],d[105];
int prim(){
    for(int i=0;i<cnt;i++) d[i] = INT_MAX/2, vis[i] = 0;
    d[0] = 0;
    int total = 0;
    for(int k=0;k<cnt;k++){
        int best = INT_MAX;
        int id = 0;
        for(int i=0;i<cnt;i++)
            if(!vis[i] && d[i]<best) best = d[i], id=i;
        vis[id] =1;
        total += d[id];
        for(int i=0;i<cnt;i++)
            if(!vis[i]&&g[id][i]<d[i]) d[i] = g[id][i];
        
    }
    return total;
}

int main()
{
    scanf("%d",&t);
    char s[100];
    while(t--){
        scanf("%d%d",&m,&n);
        gets(s);
        for(int i=0;i<n;i++){
            scanf("%c",&maze[i][0]);
            for(int j=1;j<m;j++) scanf("%c",&maze[i][j]);
            maze[i][m]=0;
            getchar();
        }
        //for(int i=0;i<n;i++)
        //  printf("%s\n",maze[i]);
        cnt = 0;
        memset(id,-1,sizeof(id));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(maze[i][j]=='S' || maze[i][j]=='A') id[i*m+j] = cnt++;
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(id[i*m+j]!=-1) bfs(i,j);
        printf("%d\n",prim());
    }
    
    return 0;
}
