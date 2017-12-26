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
#include <ctype.h>
#include <climits>
using namespace std;
const int N = 2010;
int n,m;
char s[N];
int add[26],del[26];
int dp[N][N];
int f(int i,int j){
    if(j<=i) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j] = INT_MAX;
    if(add[s[j]-'a']!=-1) dp[i][j] = min(dp[i][j], f(i,j-1)+add[s[j]-'a']);
    dp[i][j] = min(dp[i][j], f(i,j-1)+(del[s[j]-'a']==-1?0:del[s[j]-'a']));
    if(add[s[i]-'a']!=-1) dp[i][j] = min(dp[i][j], f(i+1,j)+add[s[i]-'a']);
    dp[i][j] = min(dp[i][j], f(i+1,j)+(del[s[i]-'a']==-1?0:del[s[i]-'a']));
    if(s[i]==s[j]) dp[i][j] = min(dp[i][j],f(i+1,j-1));
    
    return dp[i][j];
    
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    char c;
    int a,d;
    memset(add,-1,sizeof(add));
    memset(del,-1,sizeof(del));
    for(int i=0;i<n;i++){
        scanf(" %c%d%d",&c,&a,&d);
        //printf("%c %d %d\n",c,a,d);
        add[c-'a'] = a;
        del[c-'a'] = d;
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",f(0,m-1));
}
