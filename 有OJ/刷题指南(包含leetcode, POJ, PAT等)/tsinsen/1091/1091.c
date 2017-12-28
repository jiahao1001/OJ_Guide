#include <cstdio>

int flag[15] = {0};
int n, m_cin;

void dfs(int start, int m) {
    int i, j;
    if(m == 1) {
        for(i = start; i < n; i++) {
            for(j = 0; j < start; j++)
                if(flag[j] == 1)
                    printf("%d ", j + 1);
            printf("%d\n", i + 1);
        }
        return;
    }
    for(i = start; i <= n - m; i++) {
        flag[i] = 1;
        dfs(i + 1, m -1);
        flag[i] = 0;
    }
}

int main() {
    scanf("%d %d", &n, &m_cin);
    dfs(0, m_cin);
    return 0;
}
