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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
const int INF = INT_MAX/2;
const int N = 301;
const int M = 10001;
int g[N][M];
int d[N][N];
int n,m;
int main()
{
    int cnt,c;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&cnt);
        for(int j=0;j<cnt;j++){
            scanf("%d",&c);
            g[c][i] = 1;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i==j){
                d[i][j] = 0;
                continue;
            }
            int k =1;
            for(k=1;k<=m;k++){
                if(g[i][k] && g[j][k]) break;
            }
            if(k==m+1) d[i][j] = INF;
            else d[i][j] = 1;
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    int best = INF;
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=1;j<=n;j++)
            if(i!=j) sum+=d[i][j];
        best = min(best,sum);
    }    
    printf("%d\n",100*best/(n-1));
    
    return 0;
}
