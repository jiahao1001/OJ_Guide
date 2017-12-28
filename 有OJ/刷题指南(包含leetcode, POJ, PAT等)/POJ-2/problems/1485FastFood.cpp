#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
#include<float.h>
using namespace std;
const int N = 201;
const int K = 31;
int n,k;
int depot[N];
int ds[N][N];
int dp[N][K];
int pre[N][K];
int calc(int i,int j){
    int m = (i+j)/2;
    int tot = 0;
    while(i<=j){
        tot += abs(depot[m]-depot[i++]);
    }
    return tot;
}
void print(int n,int k){
    int l = pre[n][k];
    if(l) print(l,k-1);
    printf("Depot %d at restaurant %d serves ",k,(l+1+n)/2);
    if(l+1==n) printf("restaurant %d\n",n);
    else printf("restaurants %d to %d\n",l+1,n);
    
}
int main()
{
    int q=1;
    while(scanf("%d%d",&n,&k),n||k){
        for(int i=1;i<=n;i++)
            scanf("%d",depot+i);
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                ds[i][j] = calc(i,j);
        printf("Chain %d\n",q++);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++){
                if(j==1) {
                    dp[i][j] = ds[1][i];
                    pre[i][j] = 0;
                    continue;
                }
                dp[i][j] = INT_MAX/2;
                for(int l=0;l<i;l++){
                    if(dp[l][j-1]+ds[l+1][i]<dp[i][j])
                        dp[i][j]=dp[l][j-1]+ds[l+1][i],pre[i][j] = l;
                }
            }
        print(n,k);
        printf("Total distance sum = %d\n\n",dp[n][k]);
        
    }
    return 0;
}
