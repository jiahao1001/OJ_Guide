#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<queue>
using namespace std;
int N,h[100][100];
int vis[100][100];
struct Pt{
    int x,y;
    Pt(int _x,int _y):x(_x),y(_y){}
};
inline bool within(int x,int l,int r)
{
    return x>=l && x<=r;
}
inline bool reachable(int low,int high)
{
    const static int dx[4]={0,1,0,-1};
    const static int dy[4]={1,0,-1,0};
    if(!within(h[0][0],low,high) || !within(h[N-1][N-1],low,high))
       return false;
    memset(vis,0,sizeof(vis));
    queue<Pt> Q;
    Q.push(Pt(0,0));
    vis[0][0]=1;
    int x,y;
    while(!Q.empty()){
        Pt p=Q.front();
        Q.pop();
        if(p.x==N-1 && p.y==N-1) return true;
        for(int k=0;k<4;k++){
            x=p.x+dx[k],y=p.y+dy[k];
            if(within(x,0,N-1) && within(y,0,N-1) && !vis[x][y] && within(h[x][y],low,high))
                Q.push(Pt(x,y)),vis[x][y]=1;
        }
        
    }
    return false;
}
int main()
{
    
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) scanf("%d",&h[i][j]);
    
    for(int j=0;j<=110;j++)
    for(int i=0;i<=110;i++)
        if(reachable(i,i+j)){
            printf("%d\n",j);
            return 0;
        }
    return 0;
}
