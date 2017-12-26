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
#include <math.h>
#include <queue>
using namespace std;
int n, m, s, v;
double gopher_x[100], gopher_y[100];
double hole_x[100], hole_y[100];
int g[100][100];

inline double dist(double x, double y) {
    return sqrt(x * x + y * y);
}

inline bool escape(int i, int j) {
    return 1.0 * s * v >= dist(gopher_x[i] - hole_x[j], gopher_y[i] - hole_y[j]);
}
int vis[100], ly[100];

bool dfs(int i) {
    for (int j = 0; j < m; j++)
        if (g[i][j]&&!vis[j]) {
            vis[j] = 1;
            if (ly[j] == -1 || dfs(ly[j])) {
                ly[j] = i;
                return true;
            }
        }
    return false;
}

int max_match() {
    int mat = 0;
    memset(ly, -1, sizeof (ly));
    for (int i = 0; i < n; i++) {
        memset(vis, 0, sizeof (vis));
        if (dfs(i)) mat++;
    }
    return mat;
}

int main() {
    while (scanf("%d%d%d%d", &n, &m, &s, &v) != EOF) {
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", gopher_x + i, gopher_y + i);
        for (int i = 0; i < m; i++)
            scanf("%lf%lf", hole_x + i, hole_y + i);

        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (escape(i, j)) g[i][j] = 1;
                else g[i][j] = 0;
            }
        }
        printf("%d\n", n - max_match());
    }
    return 0;
}
