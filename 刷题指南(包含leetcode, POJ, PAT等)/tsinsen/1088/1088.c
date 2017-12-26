#include <cstdio>

int main() {
    int a[30];
    int i, j, n, s = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);


    for(i = n-1; i >= 0; i--) {
        s += a[i];
        for(j = 0; j < i; j++)
            a[j] = a[j + 1] - a[j];
    }

    printf("%d\n", s);
    return 0;
}