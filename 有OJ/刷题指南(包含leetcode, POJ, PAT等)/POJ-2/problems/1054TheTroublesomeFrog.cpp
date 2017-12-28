#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<algorithm>
using namespace std;
int paddy[5001][5001];
pair<int,int> flat[5000];
int R,C,r,c,N;
int x,y,dx,dy;
int jump(int x,int y,int dx,int dy)
{
    int step=0;
    while(x>=1 && x<=R && y>=1 && y<=C){
        if(!paddy[x][y]) return 0;
        step++,x+=dx,y+=dy;
    }
    return step;
}
int main()
{
    scanf("%d%d",&R,&C);
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&r,&c);
        flat[i]=make_pair(r,c);
        paddy[r][c]=1;
    }
    sort(flat,flat+N);
    int best=2;
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
        {
            x=flat[i].first;
            y=flat[i].second;
            dx=flat[j].first-flat[i].first;
            dy=flat[j].second-flat[i].second;
            if(x-dx>=1 && x-dx <=R && y-dy>=1 && y-dy <=C)  continue;
            if(x+best*dx<1 || x+best*dx>R) continue;
            if(y+best*dy<1 || y+best*dy>C) continue;
            int step=jump(x,y,dx,dy);
            if(step>best) best=step;
        }
    if(best==2) printf("0\n");
    else printf("%d\n",best);
    return 0;
}
