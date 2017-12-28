#include<iostream>
#include<stdio.h>
using namespace std;
const int N = 380;
int n,g[N][N];
int dp[N][N];
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};
int f(int i,int j){
    if(dp[i][j]) return dp[i][j];
    dp[i][j] = 1;
    int x,y;
    
    for(int k=0;k<8;k++){
        x=i+dx[k],y=j+dy[k];
        if(x<0 || x>=n || y<0 || y>=n) continue;
        if(g[x][y]<g[i][j]) continue;
        dp[i][j] = max(dp[i][j],f(x,y)+1);
    }
    return dp[i][j];
}
void print(int x,int y,int d){
    if(d==0) return;
    printf("%d\n",g[x][y]);
    int best = 1<<23,xx,yy;
    for(int k=0;k<8;k++){
        int nx=x+dx[k],ny=y+dy[k];
        if(nx<0 ||nx>=n || ny<0||ny>=n) continue;
        if(dp[nx][ny]==d-1){
            if(g[nx][ny]<best) best = g[nx][ny], xx=nx,yy=ny;
        }
    }
    print(xx,yy,d-1);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%d",&g[i][j]);
    int best = 0, x,y;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(f(i,j)>best || f(i,j)==best && g[i][j]<g[x][y]) best = f(i,j), x=i,y=j;
    printf("%d\n",best);
    print(x,y,best);
    return 0;
}
