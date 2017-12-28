#include<iostream>
#include<stdio.h>
using namespace std;
int A[101][101];
int N,W,H,S,T;
inline int lowbit(int x){
    return x&(-x);
}
void add(int i,int j,int x)
{
    int t;
    while(i<=W){
        t=j;
        while(t<=H) A[i][t]+=x,t+=lowbit(t);
        i+=lowbit(i);
    }
}
int sum(int i,int j)
{
    int t,total=0;
    while(i){
        t=j;
        while(t) total+=A[i][t],t-=lowbit(t);
        i-=lowbit(i);
    }
    return total;
}
int query(int x1,int y1,int x2,int y2)
{
    return sum(x2,y2)+sum(x1-1,y1-1)-sum(x1-1,y2)-sum(x2,y1-1);
}
int main()
{
    int x,y;
    while(scanf("%d",&N),N){
        memset(A,0,sizeof(A));
        scanf("%d%d",&W,&H);
        for(int i=0;i<N;i++)
            scanf("%d%d",&x,&y),add(x,y,1);
        scanf("%d%d",&S,&T);
        int persimmons = 0;
        for(int i=1;i<=W-S+1;i++)
            for(int j=1;j<=H-T+1;j++)
                persimmons = max(persimmons, query(i,j,i+S-1,j+T-1));
        printf("%d\n",persimmons);
    }
    return 0;
}
