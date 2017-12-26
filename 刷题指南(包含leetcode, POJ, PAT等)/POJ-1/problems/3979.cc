#include <stdio.h>

int gcd(int a,int b);
int gcd(int a,int b)
{
    int temp;
    if(a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    while(b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int main (int argc, const char * argv[])
{
    int a, b, c, d;
    int l, m, n;
    
    while (scanf("%d/%d%d/%d", &a, &b, &c, &d) != EOF) {
        m = a * d;
        n = c * b;
        m = m + n;
        n = b * d;
        if (m == 0) {
            printf("0\n");
        }
        else {
            if (m < 0)
                l = gcd(-m, n);
            else l = gcd(m, n);
            if (n == l)
                printf("%d\n", m/l);
            else printf("%d/%d\n", m/l, n/l);
        }
    }
    return 0;
}
