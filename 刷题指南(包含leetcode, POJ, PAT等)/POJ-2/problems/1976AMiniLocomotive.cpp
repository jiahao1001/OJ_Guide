#include<iostream>
#include<stdio.h>
using namespace std;
const int N = 50010;
int p[N];
int dp[3][N];
int n,m;
int sum[N];
inline int get(int i){
    if(i<0) return 0;
    else return sum[i];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        sum[0] = 0;
        for(int i=1;i<=n;i++)
            scanf("%d",p+i),sum[i]=sum[i-1]+p[i];
        scanf("%d",&m);
        memset(dp,0,sizeof dp);
        dp[0][0] = 0;
        for(int i=1;i<=n;i++)
            dp[0][i] = max(i<m?0:dp[0][i-1],sum[i]-get(i-m));
        for(int j=0;j<=1;j++){
            for(int i=1;i<=n;i++)
                dp[j+1][i] = max((i<1)?0:dp[j+1][i-1],(i<m?0:dp[j][i-m])+sum[i]-get(i-m));
        }
        printf("%d\n",dp[2][n]);
    }
    return 0;
}
