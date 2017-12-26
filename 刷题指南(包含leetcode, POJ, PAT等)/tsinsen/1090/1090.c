#include <cstdio>

long long cb[25];
int main() {
    int k, i, s = 0;
    cb[0] = cb[1] = 1;
    scanf("%d", &k);
    for(i = 2; i <= k; i++)
        cb[i] = i * cb[i - 1];
    for(i = 2; i <= k; i++)
        s += cb[k] / cb[i] / cb[k - i];
    s <<= 1;
    printf("%d", s);
    return 0;
}