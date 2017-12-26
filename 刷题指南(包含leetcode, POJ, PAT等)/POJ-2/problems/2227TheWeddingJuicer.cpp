#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int,pair<int,int> > p_t;
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
int w,h;
int bowl[300][300];
int visited[300][300];
int main()
{
    scanf("%d%d",&w,&h);
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++) scanf("%d",&bowl[i][j]);
    priority_queue<p_t,vector<p_t>, greater<p_t> > pq;
    for(int i=0;i<h;i++){
        int x = i, y = 0;
        int ht = bowl[x][y];
        visited[x][y] = 1;
        pq.push(make_pair(ht,make_pair(x,y)));
        x = i, y = w-1;
        ht = bowl[x][y];
        visited[x][y] = 1;
        pq.push(make_pair(ht,make_pair(x,y)));
    }
    for(int j=1;j<w-1;j++){
        int x = 0, y = j;
        int ht = bowl[x][y];
        visited[x][y] = 1;
        pq.push(make_pair(ht,make_pair(x,y)));
        x = h-1, y = j;
        ht = bowl[x][y];
        visited[x][y]=1;
        pq.push(make_pair(ht,make_pair(x,y)));
    }
    int water = 0;
    while(!pq.empty()){
        p_t head = pq.top();
        pq.pop();
        int ht = head.first, x = head.second.first, y = head.second.second;
        int nx,ny,nh;
        for(int k=0;k<4;k++){
            nx = x+dx[k], ny = y+dy[k];
            if(nx<0 || nx>= h || ny<0 || ny>=w || visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            nh = bowl[nx][ny];
            if(nh>=ht) pq.push(make_pair(nh,make_pair(nx,ny)));
            else water+= (ht-nh), pq.push(make_pair(ht,make_pair(nx,ny)));
        }
        
    }
    printf("%d\n",water);
    return 0;
    
}
