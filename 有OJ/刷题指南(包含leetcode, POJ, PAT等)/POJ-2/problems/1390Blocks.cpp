#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
const int N = 210;
int n,cnt;
int dp[N][N][N];
int len[N],col[N];

int f(int i,int j,int k){
    if(dp[i][j][k]) return dp[i][j][k];
    if(i==j) return dp[i][j][k] = (k+len[i])*(k+len[i]);
    dp[i][j][k] = f(i,j-1,0) + (k+len[j])*(k+len[j]);
    for(int m = i;m<j;m++){
        if(col[m]==col[j]) dp[i][j][k] = max(dp[i][j][k],f(i,m,k+len[j])+f(m+1,j-1,0));
    }
    return dp[i][j][k];
}

int main() {
    int T,tmp;
    scanf("%d",&T);
    int k=1;
    while (T--){
        scanf("%d",&n);
        col[0]=-1;
        cnt=0;
        for (int i=0; i<n; i++){
            scanf("%d",&tmp);
            if (tmp==col[cnt]) len[cnt]++;
            else cnt++,col[cnt]=tmp,len[cnt]=1;
        }
        memset(dp,0,sizeof(dp));
        printf("Case %d: %d\n",k++,f(1,cnt,0));
        
    }
    return 0;
}  
