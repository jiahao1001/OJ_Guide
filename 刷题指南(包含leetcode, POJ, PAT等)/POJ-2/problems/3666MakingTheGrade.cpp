/* DP
   TODO, implement leftist
 */

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<stdlib.h>
#define MAXN 2000
using namespace std;
int A[MAXN],B[MAXN];
int h,N;
int dp[MAXN][MAXN];
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&h);
        A[i]=B[i]=h;
    }
    sort(B,B+N);
    for(int j=0;j<N;j++)
        dp[0][j]=abs(A[0]-B[j]);
    for(int i=1;i<N;i++)
    {
        int t=INT_MAX;
        for(int j=0;j<N;j++)
            t=min(t,dp[i-1][j]),dp[i][j]=t+abs(A[i]-B[j]);
    }
    int ans=INT_MAX;
    for(int i=0;i<N;i++)
        ans=min(ans,dp[N-1][i]);
    printf("%d\n",ans);
    return 0;
}

