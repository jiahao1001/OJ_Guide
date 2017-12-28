#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
int dp[41][1001];
int dc[41][1001];
int m,d[41];
int h;
void print(int i,int hh){
    if(i==0)return;
    int c = dc[i][hh];
    print(i-1,hh-c*d[i]);
    if(c>0) printf("U");
    else printf("D");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&m);
        h = 0;
        for(int i=1;i<=m;i++)
            scanf("%d",d+i),h+=d[i];
        if(h%2){
            printf("IMPOSSIBLE\n");
            continue;
        }
        h/=2;
        int k;
        for(k=1;k<=h;k++){
            memset(dp,0,sizeof dp);
            dp[0][0] = 1;
            for(int i=0;i<m;i++)
                for(int j=0;j<=k;j++){
                    if(!dp[i][j]) continue;
                    if(j+d[i+1]<=k) dp[i+1][j+d[i+1]] = 1, dc[i+1][j+d[i+1]] = 1;
                    if(j-d[i+1]>=0) dp[i+1][j-d[i+1]] = 1, dc[i+1][j-d[i+1]] = -1;
                }
            if(dp[m][0]) break;
        }
        if(k>h)printf("IMPOSSIBLE\n");
        else{
            print(m,0);
            printf("\n");
        }
    }
    
    
    return 0;
}
