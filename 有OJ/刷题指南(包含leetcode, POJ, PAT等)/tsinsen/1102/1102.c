#include <cstdio>
#include <cstring>
#include <ctype.h>

char a[50], len = 0;

void d(char c) {
    int i;
    for(i = 0; i < len; i++)
        if(a[i] == c)
            break;
    if(i == len)
        return;
    for(; i < len; i++)
            a[i] = a[i + 1];
    len--;
}

void insert(char c1, char c2) {
    int i, index;
    for(i = 0, index = -1; i < len; i++)
        if(a[i] == c1)
            index = i;
    if(index == -1)
        return;
    for(i = len; i > index; i--)
        a[i] = a[i - 1];
    a[index] = c2;
    len++;
}

void replace(char c1, char c2) {
    int i;
    for(i = 0; i < len; i++)
        if(a[i] == c1)
            a[i]=c2;
}

int main() {
    char o, a1, a2;
    while((o = getchar()) != '.')
        a[len++] = o;
    a[len++] = '.';
    while(isspace(o = getchar()));
    if(o == 'D') {
        while(isspace(a1 = getchar()));
        d(a1);
    } else if(o == 'I') {
        while(isspace(a1 = getchar()));
        while(isspace(a2 = getchar()));
        insert(a1, a2);
    } else {
        while(isspace(a1 = getchar()));
        while(isspace(a2 = getchar()));
        replace(a1, a2);
    }
    for(int i = 0; i < len; i++)
        printf("%c", a[i]);
    printf("\n");
    return 0;
}