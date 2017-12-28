#include <cstdio>
#include <cstring>


int a[3000000];
int main() {
    memset(a, 0, sizeof(a));
    int n, k, s, i, r = 0, index = 0;
    scanf("%d", &n);
    a[0] = 1;
    for(k = 2; k <= n; k++) {
        for(i = 0; i <= index; i++) {
            s = a[i] * k + r;
            a[i] = s % 10;
            r = s / 10;
        }
        while(r != 0) {
            a[++index] = r % 10;
            r = r / 10;
        }
    }
    for(i = index; i >= 0; i--) 
        printf("%d", a[i]);

    return 0;
}