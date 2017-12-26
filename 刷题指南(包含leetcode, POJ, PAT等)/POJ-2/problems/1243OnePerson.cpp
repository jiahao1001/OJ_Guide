
#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int dp[31][31];
int f(int g,int l){
    if(l==0) return g;
    if(g==0) return 0;
    if(dp[g][l]!=-1) return dp[g][l];
    dp[g][l] = f(g-1,l)+f(g-1,l-1)+1;
    return dp[g][l];
}
int main(){
    //dp[g][l] = 猜 dp[g-1][l-1] + 1 missing
    //             如果过低 dp[g-1][l]
    memset(dp,-1,sizeof dp);
    int g,l;
    int q=1;
    while(scanf("%d%d",&g,&l), g||l){
        printf("Case %d: %d\n",q++,f(g,l));
    }
    return 0;
}
