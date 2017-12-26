#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int,int> PII;
const int MAXX = 1100;
const int MAXY = 1100;
const int N = 10000;

int n,X,Y;
pair<int,int> ene[N];
int dist[MAXX][MAXY];
int dist2[MAXX][MAXY];
pair<int,int> q[MAXX*MAXY];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int xi,yi,xr,yr;
void compute_distance()
{
    int s,t;
    s=t=0;
    memset(dist,-1,sizeof(dist));
    for(int i=0;i<n;i++)
        q[t++] = ene[i], dist[ene[i].first][ene[i].second] = 0;
    while(s<t){
        PII head = q[s++];
        int x = head.first, y = head.second;
        int nx,ny;
        for(int i = 0;i<4;i++){
            nx = x+dx[i], ny = y+dy[i];
            if(nx<0 || nx>=X || ny<0 || ny>=Y) continue;
            if(dist[nx][ny]!=-1) continue;
            dist[nx][ny] = dist[x][y]+1;
            q[t++] = make_pair(nx,ny);
        }
        
    }
    
    
}

int shortest(int d)
{
    
    if(dist[xi][yi]<d) return -1;
    memset(dist2,-1,sizeof(dist2));
    dist2[xi][yi] = 0;
    int s,t;
    s=t=0;
    q[t++] = make_pair(xi,yi);
    while(s<t){
        PII head = q[s++];
        int x = head.first, y = head.second;
        if(x==xr && y == yr) return dist2[x][y];
        int nx,ny;
        for(int i=0;i<4;i++){
            nx = x+dx[i], ny = y+dy[i];
            if(nx<0 || nx>=X || ny<0 || ny>=Y) continue;
            if(dist[nx][ny]<d) continue;
            if(dist2[nx][ny]!=-1) continue;
            dist2[nx][ny] = dist2[x][y] +1;
            q[t++] = make_pair(nx,ny);
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&X,&Y);
        scanf("%d%d%d%d",&xi,&yi,&xr,&yr);
        for(int i=0;i<n;i++)
            scanf("%d%d",&ene[i].first,&ene[i].second);
        compute_distance();
        int l = 0, r = X+Y;
        int mid;
        while(l+1<r){
            mid = (l+r)>>1;
            if(shortest(mid)==-1) r=mid;
            else l = mid;
        }
        printf("%d %d\n",l,shortest(l));
    }
    return 0;
}
