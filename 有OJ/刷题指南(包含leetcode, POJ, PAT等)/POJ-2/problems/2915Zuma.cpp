#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<iostream>
#include<vector>
#include<algorithm>
#pragma GCC optimize ("O2")
using namespace std;

#define f(i,j,k) (dp[i][j][k])
int M,cnt;
char color[210];
int D[210];
int dp[210][210][45];
int fore[210];
int main(){
    while(scanf("%d",&M)!=EOF){
        scanf("%s",color);
        cnt = 0;
        int tm = M<<1;
        for(int i=0;color[i];i++){
            if(i==0 || color[i]!=color[i-1]){
                color[cnt] = color[i];
                D[cnt] = 1;
                cnt ++;
            }
            else{
                D[cnt-1] ++;
            }
        }
        for(int i=0;i<cnt;i++){
            if(D[i]>=M) D[i] = M-1;
            fore[i] = -1;
            for(int j=i-1;j>=0;j--){
                if(color[j]==color[i]){
                    fore[i] = j;
                    break;
                }
            }
        }
        for(int len=0;len<cnt;len++){
            for(int i=0;i+len<cnt;i++){
                int j = i+len;
                for(int k=0;k<tm;k++){
                    int mm;
                    if(k<M) mm = max(0,M-D[j]-k);
                    else if(k+D[j]<tm) mm = 0;
                    else mm = M-D[j];
                    if(i<j) mm += dp[i][j-1][0];
                    if(D[j]+k<M){
                        for(int s=fore[j];s>=i;s=fore[s])
                            mm = min(mm,f(i,s,k+D[j])+f(s+1,j-1,0));
                    }else if(M<=D[j]+k && D[j]+k<tm){
                        if(k<M)
                            for(int s=fore[j];s>=i;s=fore[s])
                                mm = min(mm,f(i,s,M+D[j])+f(s+1,j-1,0));
                        else
                            for(int s=fore[j];s>=i;s=fore[s])
                                mm = min(mm,f(i,s,k+D[j])+f(s+1,j-1,0));
                        
                    }else if(D[j]+k>=tm){
                        for(int s=fore[j];s>=i;s=fore[s])
                            mm = min(mm,f(i,s,D[j])+f(s+1,j-1,0));
                    }
                    dp[i][j][k] = mm;
                }
            }
        }
        printf("%d\n",dp[0][cnt-1][0]);
    }
    return 0;
}
