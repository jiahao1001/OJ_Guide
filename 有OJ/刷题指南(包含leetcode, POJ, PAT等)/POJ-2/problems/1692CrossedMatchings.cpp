#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int n,m;
vector<int> X;
vector<int> Y;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        X = vector<int>(n,0),Y = vector<int>(m,0);
        for(int i=0;i<n;i++)
            scanf("%d",&X[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&Y[i]);
        vector<vector<int> > dp = vector<vector<int> >(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(j-1>=0) dp[i][j] = max(dp[i][j],dp[i][j-1]);
                if(i-1>=0) dp[i][j] = max(dp[i][j],dp[i-1][j]);
                if(X[i]==Y[j]) continue;
                int ii,jj;
                for(ii=i-1;ii>=0;ii--)
                    if(X[ii]==Y[j]) break;
                for(jj=j-1;jj>=0;jj--)
                    if(Y[jj]==X[i]) break;
                if(ii<0||jj<0) continue;
                if(ii>=1 && jj>=1) dp[i][j] = max(dp[i][j],2+dp[ii-1][jj-1]);
                else dp[i][j] = max(dp[i][j],2);
            }
        printf("%d\n",dp[n-1][m-1]);
    }
    return 0;
}
