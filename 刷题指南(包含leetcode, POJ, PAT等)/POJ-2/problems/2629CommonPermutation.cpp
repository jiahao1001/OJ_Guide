#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<algorithm>
using namespace std;
char x[1010],y[1010];
int dp[1010][1010];
int c[1010][1010];
int n,m;
void print(int i,int j){
    if(!i || !j) return;
    char cc=' ';
    if(c[i][j]==0 && x[i-1]==y[j-1])cc=x[i-1],i--,j--;
    else if(c[i][j]==-1) i--;
    else j--;
    print(i,j);
    if(cc!=' ')putchar(cc);
}
int main()
{
    while(gets(x)){
        memset(dp,0,sizeof dp);
        memset(c,0,sizeof c);
        gets(y);
        n = strlen(x), m = strlen(y);
        sort(x,x+n),sort(y,y+m);
        //cout<<x<<" "<<y<<endl;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                int d = 0;
                if(x[i-1]==y[j-1]) d++;
                dp[i][j] = dp[i-1][j-1]+d;
                if(dp[i-1][j]>dp[i][j]) dp[i][j] = dp[i-1][j],c[i][j] = -1;
                if(dp[i][j-1]>dp[i][j]) dp[i][j] = dp[i][j-1],c[i][j] = 1;
            }
        print(n,m);
        printf("\n");
    }
    return 0;
}
