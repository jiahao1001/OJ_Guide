#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 1450;
int arrival[N];
int dp[N],trip[N];
int main()
{
    int k,n,t,m;
    scanf("%d",&k);
    while(k--){
        scanf("%d%d%d",&n,&t,&m);
        for(int i=1;i<=m;i++) scanf("%d",arrival+i);
        for(int i=0;i<=m;i++) dp[i] = INT_MAX/2, trip[i] = INT_MAX/2;
        dp[0] = 0, trip[0] = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n && i-j>=0;j++){
                //last one is i-j
                int cur;
                if(dp[i-j]<=arrival[i]) cur = arrival[i]+2*t;
                else cur = dp[i-j]+2*t;
                if(cur<dp[i]) dp[i] = cur, trip[i] = trip[i-j]+1;
                else if(cur==dp[i]) trip[i] = min(trip[i],trip[i-j]+1);
                
            }
        }
        printf("%d %d\n",dp[m]-t,trip[m]);
    }
    return 0;
}
