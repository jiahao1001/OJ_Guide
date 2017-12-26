#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
const int maxn = 1010;
const int maxm = 1000100;
int map[maxn][maxn];
int n, m;
int dfn[maxn], low[maxn], dep;
int scc, tmp[maxn], block[maxn];
int color[maxn]; //给某个双连通深度优先搜索染色
int expell[maxn]; //标记顶点是否在某个奇圈中
int cnt;
stack <int> st;
vector <int> edge[maxn]; //补图

void init() {
    for (int i = 1; i <= n; i++)
        edge[i].clear();
    while (!st.empty()) st.pop();
    memset(map, 0, sizeof (map));
    memset(dfn, 0, sizeof (dfn));
    memset(low, 0, sizeof (low));
    memset(block, 0, sizeof (block));
    memset(expell, 0, sizeof (expell));
    dep = 0;
    cnt = 0;
    scc = 0;
}


bool odd_cycle(int u, int col) {
    color[u] = col;

    for (int i = 0; i < (int) edge[u].size(); i++) {
        int v = edge[u][i];
        if (block[v] == scc) {
            if (color[v] && color[v] == color[u])
                return true;
            if (!color[v] && odd_cycle(v, -col))
                return true;
        }
    }
    return false;
}

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++dep;
    st.push(u);
    for (int i = 0; i < (int) edge[u].size(); i++) {
        int v = edge[u][i];
        if (v == fa) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                scc++;
                int t;
                do {
                    t = st.top();
                    st.pop();
                    tmp[++cnt] = t;
                    block[t] = scc;
                } while (t != v); //注意不要让u出栈，因为它可能属于多个双连通分量 u is a cut
                tmp[++cnt] = u; //u进临时数组 
                memset(color, 0, sizeof (color));
                if (cnt >= 3 && odd_cycle(u, 1))//若该双连通分量包含顶点个数大于2并且是奇圈时
                {
                    while (cnt != 0)
                        expell[ tmp[cnt--] ] = 1; //在奇圈内的点全部标记为1
                } else cnt = 0; //别忘了将cnt置零
            }
        } else if (dfn[v] < dfn[u])
            low[u] = min(low[u], dfn[v]);
    }
}

int main() {
    int u, v;
    while (~scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) break;

        init();

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            map[u][v] = map[v][u] = 1;
        }

        for (int i = 1; i <= n - 1; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!map[i][j]) {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i, -1);
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (expell[i] == 0)
                res++;
        printf("%d\n", res);
    }
    return 0;
}
