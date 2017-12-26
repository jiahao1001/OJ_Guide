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
using namespace std;
int n;
char board[34][40];
long long dp[34][34];
int main()
{
    while(scanf("%d",&n),n!=-1)
    {
        for(int i=0;i<n;i++)
            scanf("%s",board[i]);
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                int d = board[i][j]-'0';
                if(d==0) continue;
                if(j+d<n) dp[i][j+d] += dp[i][j];
                if(i+d<n) dp[i+d][j] += dp[i][j];
            }
        
        printf("%lld\n",dp[n-1][n-1]);
                
    }
    return 0;
}
