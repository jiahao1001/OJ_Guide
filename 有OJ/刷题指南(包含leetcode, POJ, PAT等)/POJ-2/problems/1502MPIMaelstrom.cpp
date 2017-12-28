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
const int INF = INT_MAX / 2;
const int N = 100;
int g[N][N];
int n, w;
char buf[20];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) g[i][j] = INF;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++) {
            scanf("%s", buf);
            if(buf[0]=='x') continue;
            g[i][j] = g[j][i] = atoi(buf);
        }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    int best = 0;
    for (int i = 1; i < n; i++) best = max(best, g[0][i]);
    printf("%d\n", best);
    return 0;

}
