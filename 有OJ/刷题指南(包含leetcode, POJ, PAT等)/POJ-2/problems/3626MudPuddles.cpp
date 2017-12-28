#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <climits>
#include <math.h>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
int off = 501;
int x_min = -501, x_max = 501;
int y_min = -501, y_max = 501;
int mud[1003][1003];
int X,Y;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dist[1003][1003];

inline int bfs()
{
    memset(dist,-1,sizeof(dist));
    int nx,ny,x,y;
    dist[off][off] = 0;
    queue<PII> Q;
    Q.push(make_pair(0,0));
    while(!Q.empty()){
        PII head = Q.front();
        x = head.first, y = head.second;
        int d = dist[off+x][off+y];
        Q.pop();
        if(x==X && y== Y) return d;
        for(int k=0;k<4;k++){
            nx = head.first+dx[k],ny = head.second+dy[k];
            if(nx<x_min || nx>x_max || ny<y_min || ny>y_max) continue;
            PII p = make_pair(nx,ny);
            if(mud[off+nx][off+ny]||dist[off+nx][off+ny]!=-1) continue;
            dist[off+nx][off+ny] = d+1;
            Q.push(p);     
        }
    }
    return 0;
}
int main()
{
    int n,x,y;
    scanf("%d%d%d",&X,&Y,&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        mud[off+x][off+y] = 1;
    }
    printf("%d\n",bfs());
    return 0;
}
