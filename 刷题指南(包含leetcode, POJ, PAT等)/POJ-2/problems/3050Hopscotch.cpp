#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;
int g[5][5];
set<int> v;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int i,int j,int cur,int d){
    if(cur==6){
        //cout<<d<<endl;
        v.insert(d);
        return;
    }
    int x,y;
    for(int k=0;k<4;k++){
        x=i+dx[k],y=j+dy[k];
        if(x<0||x>=5 ||y<0 ||y>=5) continue;
        dfs(x,y,cur+1,d*10+g[x][y]);
    }
}
int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&g[i][j]);
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            dfs(i,j,1,g[i][j]);
    
    printf("%d\n",(int)v.size());
    return 0;
}
