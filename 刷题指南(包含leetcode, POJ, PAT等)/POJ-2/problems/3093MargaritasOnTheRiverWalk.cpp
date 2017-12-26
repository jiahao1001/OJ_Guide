#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
LL dp[1005];//dp(i,j) spend i, least P[j]
int P[31];
LL sum[1005];
int main()
{
    int t;
    scanf("%d",&t);
    int V,D;
    for(int q=1;q<=t;q++){
        scanf("%d%d",&V,&D);
        for(int i=1;i<=V;i++)
            scanf("%d",P+i);
        sort(P+1,P+V+1);
        memset(dp,0,sizeof dp);
        if(P[1]>D){
            printf("%d 0\n",q);
            continue;
        }
        sum[0] = 0;
        for(int i=1;i<=V;i++)
            sum[i] = sum[i-1]+P[i];
        LL answer = 0;
        for(int i=1;i<=V;i++){
            if(sum[i-1]>D) break;
            memset(dp,0,sizeof dp);
            dp[sum[i-1]] = 1;
            for(int j=i+1;j<=V;j++)
                for(int k=D;k>=sum[i-1]+P[j];k--)
                    dp[k] += dp[k-P[j]];
            for(int j=D-P[i]+1;j<=D;j++)
                answer += dp[j];
        }
        if(sum[V]<=D) answer++;
        printf("%d %lld\n",q,answer);
        
    }
    return 0;
}
