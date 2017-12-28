#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
#include<string.h>
using namespace std;
const int MAXN = 10000;
long long dp[1001][1001]; // L,C
int L,N,B;
long long F[MAXN];
int X[MAXN], W[MAXN], C[MAXN];
int id[MAXN];
bool cmp(const int& i,const int &j){
    return X[i]<X[j];
}
int main()
{
    scanf("%d%d%d",&L,&N,&B);
    for(int i=0;i<N;i++)
        scanf("%d%d%lld%d",X+i,W+i,F+i,C+i);
    for(int i = 0;i<N;i++) id[i] = i;
    sort(id,id+N,cmp);
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    //(i,j) L,C
    for(int kk=0;kk<N;kk++){
        int k = id[kk];
        for(int j=0;j+C[k]<=B;j++)
                if(dp[X[k]][j]!=-1 && j+C[k]<=B)
                    dp[X[k]+W[k]][j+C[k]] = max(dp[X[k]+W[k]][j+C[k]],dp[X[k]][j]+F[k]);
    }
    
    long long best = -1;
    for(int i=1;i<=B;i++) best = max(best,dp[L][i]);
    printf("%lld\n",best);
    
    return 0;
}
