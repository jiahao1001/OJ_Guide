#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;
const int inf = INT_MAX/2;
int S,N;
int d[10],k;
int dp[1001];
int answer[10],kk;
int best;
int main()
{
    while(scanf("%d",&S),S){
        scanf("%d",&N);
        best = -1;
        while(N--){
            scanf("%d",&k);
            for(int i=0;i<k;i++)
                scanf("%d",d+i);
            int m = d[k-1]*S;
            for(int i=0;i<=m;i++) dp[i] = inf;
            dp[0] = 0;
            for(int i=0;i<k;i++)
                for(int j=0;j+d[i]<=m;j++)
                    dp[j+d[i]] = min(dp[j+d[i]],dp[j]+1);
            int cover = 0;
            for(;cover<=m;cover++){
                //printf("dp %d->%d\n",cover,dp[cover]);
                if(dp[cover]>S) break;
            }
            if(cover-1>best || (cover-1==best && k<kk) || (cover-1==best && k==kk && d[k-1]<answer[kk-1])) {
                best = cover-1;
                kk = k;
                for(int i=0;i<k;i++) answer[i] = d[i];
            }
        }
        printf("max coverage = %d :",best);
        for(int i=0;i<kk;i++)
            printf(" %d",answer[i]);
        printf("\n");
    }
    return 0;
}
