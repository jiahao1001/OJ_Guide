#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <climits>
using namespace std;
const int N = 100010;
int dp[2][2*N+1];
int main(){
    int n,s,f;
    scanf("%d",&n);
    for(int i=0;i<2;i++)
        for(int j=0;j<2*N+1;j++) dp[i][j] = INT_MIN;
    scanf("%d%d",&s,&f);
    int cur = 1, prev = 0;
    dp[0][s+N] = f;
    dp[0][N] = 0;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&s,&f);
        for(int j=0;j<=2*N;j++) dp[cur][j] = INT_MIN;
        for(int j=0;j<=2*N;j++){
            if(dp[prev][j]!=INT_MIN && j+s>=0 && j+s<=2*N) dp[cur][j+s] = max(dp[cur][j+s],dp[prev][j]+f);
            dp[cur][j] = max(dp[cur][j],dp[prev][j]);
        }
        cur ^= 1;
        prev ^=1;
    }
    int best = 0;
    for(int i=N;i<=2*N;i++)
        if(dp[prev][i]!=INT_MIN && dp[prev][i]>=0) best = max(best,dp[prev][i]+i-N);
    printf("%d\n",best);
    
    return 0;
}
