#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string.h>
#include<stack>
#include<set>
#include<string>
#include<limits.h>
#include<algorithm>
using namespace std;
int dp[100][100];
int A[100];
int f(int i,int j){
    if(i+1==j) return dp[i][j]=0;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j] = INT_MAX;
    for(int k=i+1;k<j;k++) dp[i][j] = min(dp[i][j],f(i,k)+f(k,j)+A[i]*A[k]*A[j]);
    return dp[i][j];
}
int main(){
    int n;
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) scanf("%d",A+i);
    printf("%d\n",f(0,n-1));
    
}
