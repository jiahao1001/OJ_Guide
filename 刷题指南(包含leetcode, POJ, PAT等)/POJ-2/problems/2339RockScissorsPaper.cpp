#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
int n,m,d;
int t;
char g[2][100][120];
int dx[4] ={0,0,1,-1};
int dy[4] ={1,-1,0,0};
bool kill(char a,char b){
    if(a=='R' && b=='S') return true;
    if(a=='S' && b == 'P') return true;
    if(a=='P' && b=='R') return true;
    return false;
}
char get(int cur,int i,int j){
    char c = g[cur][i][j];
    for(int k=0;k<4;k++){
        int x = i+dx[k],y = j+dy[k];
        if(x<0 || x>=n || y<0 || y>=m)continue;
        if(kill(g[cur][x][y],c)){
            c = g[cur][x][y];
            break;
        }
    }
    return c;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&d);
        int cur = 0, nxt = 1;
        for(int i=0;i<n;i++)
            scanf("%s",g[cur][i]);
        while(d--){
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++){
                    g[nxt][i][j] = get(cur,i,j);
                }
            cur ^= 1, nxt ^= 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                printf("%c",g[cur][i][j]);
            printf("\n");
        }
        if(t) printf("\n");
    }
    return 0;
}
