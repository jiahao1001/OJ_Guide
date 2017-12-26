#include <cstdio>
#include <cstdlib>
#include <cstring>

char sub[250][1010];
char a[1010];

int cmp(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    int n, k;
    int i, j;
    scanf("%s", a);
    scanf("%d", &k);
    n = strlen(a);
    for(i = 0; i <= n - k; i++) {
        for(j = 0; j < k; j++)
            sub[i][j] = a[i + j];
        sub[i][k] = 0;
    }
    qsort(sub, n - k + 1, sizeof(sub[0]), cmp);
    for(i = 0; i <= n - k; i++) {
        printf("%s ", sub[i]);
    }
    return 0;
}