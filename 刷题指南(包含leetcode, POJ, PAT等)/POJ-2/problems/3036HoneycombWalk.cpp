#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int dp[15][41][41];
int f(int x,int y,int s)
{
    if(dp[s][x][y]!=-1) return dp[s][x][y];
    if(!s){
        if(x==20 && y==20) return dp[s][x][y]=1;
        else return dp[s][x][y]=0;
    }
    return dp[s][x][y]=f(x-1,y,s-1)+f(x+1,y,s-1)+f(x,y-1,s-1)+f(x+1,y-1,s-1)+f(x,y+1,s-1)+f(x-1,y+1,s-1);
    
    
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int t,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&s);
        printf("%d\n",f(20,20,s));
    }
    return 0;
}
