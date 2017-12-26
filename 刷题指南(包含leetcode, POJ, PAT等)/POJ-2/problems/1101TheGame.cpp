#include<iostream>
#include<stdio.h>
#include<queue>
#include<utility>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef pair<int,int> PII;
int w,h;
char bd[80][80];
char buf[80];
int seg[80][80];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
inline int bfs(int x1,int y1,int x2,int y2){
    memset(seg,-1,sizeof seg);
    queue<PII> Q;
    int x,y;
    for(int k=0;k<4;k++){
        x=x1+dx[k],y=y1+dy[k];
        while(x>=0 && x<=h+1 && y>=0 && y<=w+1 && bd[x][y]!='X'){
            seg[x][y] = 1;
            Q.push(make_pair(x,y));
            x+=dx[k],y+=dy[k];
        }
        if(x==x2 && y==y2) return 1;
    }
    while(!Q.empty()){
        PII hd = Q.front();
        Q.pop();
        x1 = hd.first, y1=hd.second;
        int d = seg[x1][y1];
        for(int k=0;k<4;k++){
            x=x1+dx[k],y=y1+dy[k];
            while(x>=0 && x<=h+1 && y>=0 && y<=w+1 && bd[x][y]!='X'){
                if(seg[x][y]!=-1) {
                    x+=dx[k],y+=dy[k];
                    continue;
                }
                seg[x][y] = d+1;
                Q.push(make_pair(x,y));
                x+=dx[k],y+=dy[k];
            }
            if(x==x2 && y==y2) return d+1;
        }
    }
    return -1;
}
int main()
{
    int x1,y1,x2,y2;
    int b = 1;
    int p;
    while(scanf("%d%d",&w,&h),w||h){
        printf("Board #%d:\n",b++);
        memset(bd,' ',sizeof bd);
        gets(buf);
        for(int i=1;i<=h;i++)
            gets(bd[i]+1);
        p = 1;
        while(scanf("%d%d%d%d",&y1,&x1,&y2,&x2),x1||y1||x2||y2){
            printf("Pair %d: ",p++);
            int ans = bfs(x1,y1,x2,y2);
            if(ans==-1) printf("impossible.\n");
            else printf("%d segments.\n",ans);
        }
        printf("\n");
    }
    return 0;
}
