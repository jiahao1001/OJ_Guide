#include <stdio.h>

int main (int argc, const char * argv[])
{
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF) {
        printf("%d\n", m % n);
    }
    return 0;
}
