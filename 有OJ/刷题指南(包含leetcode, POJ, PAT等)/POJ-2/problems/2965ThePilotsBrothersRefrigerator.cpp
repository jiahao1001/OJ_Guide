#include<iostream>
#include<stdio.h>
using namespace std;
char board[4][6];
int flipped[4][6];
inline void flip(int i,int j)
{
    for(int k=0;k<4;k++)
        flipped[i][k]^=1;
    for(int k=0;k<4;k++)
        flipped[k][j]^=1;
    flipped[i][j]^=1;
}
inline int check(int s,bool print)
{
    
    int cnt = 0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            flipped[i][j]=(board[i][j]=='-'?0:1);
    
    for(int i=0;i<16;i++)
        if((s>>i)&1){
         flip(i/4,i%4),cnt++;
         if(print) printf("%d %d\n",(i/4)+1,(i%4)+1);
        }
    
    
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(flipped[i][j]) return -1;
    return cnt;
    
    
}
int main()
{
    for(int i=0;i<4;i++)
        scanf("%s",board[i]);
    int cnt=INT_MAX;
    int max_s;
    for(int s=0;s<(1<<16);s++){
        int t=check(s,false);
        if(t!=-1 && t<cnt) cnt=t,max_s=s;
    }
    printf("%d\n",cnt);
    check(max_s,true);
    return 0;
}
