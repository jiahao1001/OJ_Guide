#include <cstdio>
#include <cstring>

char a[110], b[110], c[110];
int main() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));

    scanf("%s", a);
    scanf("%s", b);

    int lena, lenb, minlen, r = 0;
    lena = strlen(a);
    lenb = strlen(b);

    int i = 0, j = 0, sum = 0;
    while(lena > 0 || lenb > 0 || r != 0) {
        if(lena == 0 && lenb == 0) {
            c[i++] = r;
            break;
        }
        
        if(lena > 0 && lenb > 0)
            sum = a[lena-- - 1] + b[lenb-- - 1] + r - 2 * '0';
        else if(lena > 0)
            sum = a[lena-- -1] + r - '0';
        else if(lenb > 0)
            sum = b[lenb-- -1] + r - '0';

        c[i++] = sum % 10;
        r = sum / 10;
    }

    for(j = i - 1; j >= 0; j--)
        printf("%d", c[j]);

    return 0;
}