#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
const int W = 20;
const int H = 20;
int w,h;
int g[H][W];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool dfs(int i,int j,int step, int d){
    if(step>=d) return false;
    //four directions
    for(int k=0;k<4;k++){
        int m = 0;
        while(i+m*dx[k]>=0 && i+m*dx[k]<h && j+m*dy[k]>=0 && j+m*dy[k]<w && g[i+m*dx[k]][j+m*dy[k]]==0) m++;
        int bi = i+m*dx[k],bj = j+m*dy[k];
        //printf("(%d,%d)->\n",bi,bj);
        if(bi<0 || bi>=h || bj<0 || bj>=w){
            //out of board, fails
            continue;
        }
        //printf("(%d,%d)->%d\n",bi,bj,g[bi][bj]);
        int block = g[bi][bj];
        if(block==3 && step<d){
            return true;
        }
        m--;
        if(m==0) continue;
        g[bi][bj] = 0;
        if(dfs(i+m*dx[k],j+m*dy[k],step+1,d)){
            g[bi][bj] = 1;
            return true;
        }
        g[bi][bj] = 1;
    }
    return false;
}
int main(){
    int si=0,sj=0;
    while(scanf("%d%d",&w,&h),w||h){
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++){
                scanf("%d",&g[i][j]);
                if(g[i][j]==2) g[i][j]=0,si=i,sj=j;
            }
        
        int d=0;
        for(d=0;d<11;d++){
            //cout<<"----"<<d<<endl;
            if(dfs(si,sj,0,d)) break;
        }
        if(d==11)printf("-1\n");
        else printf("%d\n",d);
    }
    
    return 0;
}
