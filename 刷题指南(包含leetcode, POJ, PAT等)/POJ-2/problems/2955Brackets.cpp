#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
char s[120];
int dp[120][120];
int match(char c1,char c2){
    if(c1=='[' && c2==']') return 2;
    if(c1=='(' && c2==')') return 2;
    return 0;
}
int main(){
    while(scanf("%s",s),strcmp(s,"end")){
        int n = strlen(s);
        memset(dp,0,sizeof dp);
        for(int len=1;len<n;len++){
            for(int i=0;i+len<n;i++){
                dp[i][i+len] = dp[i+1][i+len-1]+match(s[i],s[i+len]);
                for(int k=i;k<i+len;k++)
                    dp[i][i+len] = max(dp[i][i+len],dp[i][k]+dp[k+1][i+len]);
            }
        }
        printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
