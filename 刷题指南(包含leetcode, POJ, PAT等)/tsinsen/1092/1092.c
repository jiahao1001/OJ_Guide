#include <cstdio>

int main() {
    char a[4], tmp;
    bool flag = true;
    int i;
    for(i = 0; i < 4; i++) {
        scanf("%c", &a[i]);
        a[i] = ((a[i] - '0' + 5) % 10) + '0';
    }
    tmp = a[3];
    a[3] = a[0];
    a[0]= tmp;
    tmp = a[2];
    a[2] = a[1];
    a[1] = tmp;
    for(i = 0; i < 4; i++) {
        if(a[i] == '0' && flag)continue;
        printf("%c", a[i]);
        flag = false;
    }
    return 0;
}