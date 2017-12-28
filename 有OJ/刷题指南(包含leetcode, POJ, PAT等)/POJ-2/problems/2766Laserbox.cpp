#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int g[52][52];
int v[52][52];
int main()
{
    int t,x,y,n,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&r);
        memset(g,0,sizeof g);
        for(int i=0;i<r;i++){
            scanf("%d%d",&x,&y);
            g[x][y] = 1;
        }
        scanf("%d%d",&x,&y);
        int dir;
        if(y==0) dir = 0;
        if(y==n+1) dir = 2;
        if(x==0) dir = 1;
        if(x==n+1) dir =3;
        memset(v,0,sizeof v);
        int s=0;
        for(;s<=100000;s++){
            x+=dx[dir], y+=dy[dir];
            //printf("(%d,%d)\n",x,y);
            if(g[x][y]) dir = (dir+1)%4;
            if(x==0 || x==n+1 || y==0 || y==n+1) break;
        }
        if(s>100000) printf("0 0\n");
        else
        printf("%d %d\n",x,y);
        
    }
    return 0;
}
