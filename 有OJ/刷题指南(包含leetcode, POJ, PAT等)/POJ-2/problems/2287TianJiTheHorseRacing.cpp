#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <climits>
using namespace std;
const int N = 1010;
int tian[N];
int king[N];
int n;
int g[N][N];
int dp[N][N];
int main()
{
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++) scanf("%d",tian+i);
        for(int i=1;i<=n;i++) scanf("%d",king+i);
        sort(tian+1,tian+n+1,greater<int>());
        sort(king+1,king+n+1,greater<int>());
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) {
                if(tian[i]>king[j]) g[i][j]=200;
                else if(tian[i]==king[j]) g[i][j]=0;
                else g[i][j]=-200;
            }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            dp[i][0] = dp[i-1][0]+g[n-i+1][i];
            for(int j=1;j<=i;j++){
                if(i-1<j) dp[i][j]=dp[i-1][j-1]+g[j][i];
                else dp[i][j]=max(dp[i-1][j]+g[n-(i-j)+1][i],dp[i-1][j-1]+g[j][i]);
            }
        }
        int best = INT_MIN;
        for(int i=0;i<=n;i++)
            best = max(best,dp[n][i]);
        printf("%d\n",best);
    }
    return 0;
}
