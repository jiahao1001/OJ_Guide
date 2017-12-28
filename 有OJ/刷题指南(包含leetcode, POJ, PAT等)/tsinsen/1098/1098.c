#include <cstdio>

int n, m, len = 1;
int a[20] = {1};

void dfs1(int k) {
    int i;
    if(k == 0) {
        printf("%d=", n);
        for(i = 1; i < len - 1; i++)
            printf("%d+", a[i]);
        printf("%d\n", a[i]);
        return;
    }
    for(i = 1; i <= k; i++) {
        a[len++] = i;
        dfs1(k - i);
        a[--len] = 0;
    }
}

void dfs2(int k) {
    int i;
    if(k == 0) {
        printf("%d=", n);
        for(i = 1; i < len - 1; i++)
            printf("%d+", a[i]);
        printf("%d\n", a[i]);
        return;
    }
    for(i = a[len - 1]; i <= k; i++) {
        a[len++] = i;
        dfs2(k - i);
        a[--len] = 0;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    if(m == 1)dfs1(n);
    else dfs2(n);
    return 0;
}