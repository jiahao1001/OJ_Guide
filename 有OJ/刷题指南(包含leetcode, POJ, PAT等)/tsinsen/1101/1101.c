#include <stdio.h>

int main() {
    int n, i, j, k, l;
    scanf("%d %d %d", &n, &i, &j);
    for(k = 1; k <= n; k++)
        printf("(%d,%d)", i, k);
    printf("\n");
    for(k = 1; k <= n; k++)
        printf("(%d,%d)", k, j);
    printf("\n");
    for(k = 1; k <= n; k++)
        for(l = 1; l <= n; l++)
            if(i - j == k - l)
                printf("(%d,%d)", k, l);
    printf("\n");
    for(k = n; k > 0; k--)
        for(l = 1; l <= n; l++)
            if(i + j == k + l)
                printf("(%d,%d)", k, l);
    printf("\n");
    return 0;
}