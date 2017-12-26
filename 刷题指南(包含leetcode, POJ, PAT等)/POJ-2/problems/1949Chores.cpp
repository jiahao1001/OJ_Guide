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
const int N = 10001;
vector<int> prerequisite[N];
int cost[N];
int shortest[N];
int n,k,b;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",cost+i);
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%d",&b);
            prerequisite[b].push_back(i);
        }
    }
    memset(shortest,0,sizeof(shortest));
    int best = cost[1];
    for(int i=1;i<=n;i++){
        for(int j=0;j<prerequisite[i].size();j++){
            b = prerequisite[i][j];
            shortest[b] = max(shortest[i]+cost[i],shortest[b]);
            best = max(best,shortest[b]+cost[b]);
        }
    }
    printf("%d\n",best);
    return 0;
}
