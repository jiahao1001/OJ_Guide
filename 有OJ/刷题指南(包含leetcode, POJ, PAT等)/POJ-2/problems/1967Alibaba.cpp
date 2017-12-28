#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<set>
#include<string.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int x[10000],t[10000];
int n;
int dp[2][10000][2];
const int inf = 0x3f3f3f3f;
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",x+i,t+i);
        }
        int cur,la;
        memset(dp,0x3f,sizeof dp);
        cur = 0;
        for(int i=0;i<n;i++)dp[cur][i][0] = dp[cur][i][1] = 0;
        for(int k=1;k<=n-1;k++){
            cur = 1-cur;
            la = 1-cur;
            for(int i=0;i<n;i++) dp[cur][i][0]=dp[cur][i][1] = inf;
            for(int i=0;i+k<n;i++){
                int LK = x[i+k]-x[i];
                if(dp[la][i+1][0]+x[i+1]-x[i]<t[i])
                    dp[cur][i][0] = min(dp[cur][i][0], dp[la][i+1][0]+x[i+1]-x[i]);
                if(dp[la][i+1][1]+LK<t[i])
                    dp[cur][i][0] = min(dp[cur][i][0],dp[la][i+1][1]+LK);
                
                if(dp[la][i][0]+LK<t[i+k])
                    dp[cur][i][1] = min(dp[cur][i][1],dp[la][i][0]+LK);
                if(dp[la][i][1]+x[i+k]-x[i+k-1]<t[i+k])
                    dp[cur][i][1] = min(dp[cur][i][1],dp[la][i][1]+x[i+k]-x[i+k-1]);
            }
        }
        int ans =min(dp[cur][0][0],dp[cur][0][1]);
        if(ans==inf) printf("No solution\n");
        else printf("%d\n",ans);
    }
    return 0;
}
