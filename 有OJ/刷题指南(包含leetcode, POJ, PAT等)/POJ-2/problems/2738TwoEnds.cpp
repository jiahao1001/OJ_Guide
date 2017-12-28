#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
const int N = 1000;
int dp[N][N];
int A[N];
int n;
int f(int i,int j){
    if(dp[i][j]!=INT_MIN/2) return dp[i][j];
    if(i==j) return dp[i][j] = A[i];
    if(i+1==j) return dp[i][j] = max(A[i]-A[j],A[j]-A[i]);
    int l = A[i], r = A[j];
    if(A[i+1]>=A[j]) l = l-A[i+1]+f(i+2,j);
    else l = l-A[j]+f(i+1,j-1);
    if(A[i]>=A[j-1]) r = r-A[i] + f(i+1,j-1);
    else r = r-A[j-1] + f(i,j-2);
    return dp[i][j] = max(l,r);
}
int main()
{
    int q=1;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++)
            scanf("%d",A+i);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) dp[i][j] = INT_MIN/2;
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",q++,f(0,n-1));
    }
    return 0;
}
