#include <stdio.h>
int main(void)
{
    int a, b, d = 0, i = 0;
    scanf("%d%d", &a, &b);
    printf("%4d\n", a);
    printf("*%3d\n", b);
    if (b < 10)
    {
        printf("----\n");
        printf("%d\n", a*b);
    }
    else
    {
        printf("----\n");
        printf("%4d\n", b % 10 * a);
        printf("%3d\n", b / 10 * a);
        printf("----\n");
        printf("%4d\n", a*b);
    }
    return 0;
}