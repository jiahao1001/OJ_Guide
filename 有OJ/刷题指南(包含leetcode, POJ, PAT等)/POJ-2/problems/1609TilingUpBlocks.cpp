#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;
int a[101][101],dp[101][101];
int main(){
    int n,x,y;
    while(scanf("%d",&n),n){
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        while(n--){
            scanf("%d%d",&x,&y);
            a[x][y]++;
        }
        for(int i=1;i<=100;i++)
            for(int j=1;j<=100;j++) dp[i][j] = max(dp[i-1][j],dp[i][j-1])+a[i][j];
        printf("%d\n",dp[100][100]);
    }
    printf("*\n");
    return 0;
}
