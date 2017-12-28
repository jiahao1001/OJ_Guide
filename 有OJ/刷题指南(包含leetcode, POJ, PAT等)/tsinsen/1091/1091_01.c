
/* 0-1转换法 */
/* 输出不是字典序 */

#include <cstdio>
#include <cstring>

int flag[13];
int n, m;

void move(int num, int r) {
    int i;
    for(i = 0; i < num; i++)
        flag[i] = 1;
    for(i = num; i < r; i++)
        flag[i] = 0;
}

void print() {
    int i;
    for(i = 0; i < n; i++)
        if(flag[i] == 1)
            printf("%d", i + 1);
    printf("\n");
}

int find(int &num) {
    int i;
    for(i = 0; i < n; i++) {
        if(flag[i] == 1 && flag[i + 1] == 0)
            break;
        if(flag[i] == 1)
            num++;
    }
    return i;
}

void swap(int i, int j) {
    int tmp = flag[i];
    flag[i] = flag[j];
    flag[j] = tmp;
}

int main() {
    int i, num = 0;
    scanf("%d %d", &n, &m);
    memset(flag, 0, sizeof(flag));
    for(i = 0; i < m; i++)
        flag[i] = 1;

    print();
    while((i = find(num)) != n - 1) {
        swap(i, i + 1);
        move(num, i);
        print();
        num = 0;
    }

    return 0;
}