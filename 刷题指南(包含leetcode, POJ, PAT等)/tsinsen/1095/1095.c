#include <cstdio>

int main() {
    int cls[] = {120, 40, 85, 50, 100, 140, 70, 100};
    int i, j, k, l, a, b, c, d, flag = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            if(i == j) continue;
            for(k = 0; k < 8; k++) {
                if(i == k || j == k) continue;
                for(l = 0; l < 8; l++) {
                    if(i == l || j == l || k == l) continue;
                    if(a <= cls[i] && b <= cls[j] && c <= cls[k] && d <= cls[l]) {
                        printf("%d %d %d %d\n", i + 1, j + 1, k + 1, l + 1);
                        flag = 1;
                    }
                }
            }
        }
    }

    if(!flag)printf("-1\n");

    return 0;
}