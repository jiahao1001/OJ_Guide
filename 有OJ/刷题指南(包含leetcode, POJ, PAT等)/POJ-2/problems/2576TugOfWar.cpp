#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 110;
int tug[N];
int n;
int dp[N][45001]; //i people, w reachable
int main()
{
    scanf("%d",&n);
    int total = 0;
    for(int i=1;i<=n;i++) scanf("%d",tug+i), total += tug[i];
    memset(dp,0,sizeof dp);
    dp[0][0] = 1;
    for(int k=1;k<=n;k++)
        for(int i=0;i<k;i++)
            for(int j=0;j+tug[k]<=45000;j++)
                if(dp[i][j]) dp[i+1][j+tug[k]] = 1;
    
    int best = INT_MAX;
    int answer = 0;
    for(int i=0;i<=total;i++){
        if(dp[n/2][i] && abs(total-i-i)<best) best = abs(total-i-i), answer = i;
    }
    printf("%d %d\n",min(total-answer,answer),max(total-answer,answer));
    return 0;
}
