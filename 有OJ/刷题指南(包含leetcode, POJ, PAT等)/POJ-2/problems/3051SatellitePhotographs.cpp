#include<stdio.h>
#include<iostream>
using namespace std;
int W,H;
char land[1000][90];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int dfs(int i,int j)
{
    if(i<0||i>=H||j<0||j>=W) return 0;
    if(land[i][j]=='.') return 0;
    land[i][j]='.';
    int tot=1;
    for(int k=0;k<4;k++)
        tot+=dfs(i+dx[k],j+dy[k]);
    return tot;
}
int main()
{
    scanf("%d%d",&W,&H);
    for(int i=0;i<H;i++)
        scanf("%s",land[i]);
    
    int best=0;
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            if(land[i][j]=='*') best=max(best,dfs(i,j));
    printf("%d\n",best);
}
