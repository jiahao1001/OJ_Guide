#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int L, N, i, c, tmin = 0, tmax = 0;
    scanf("%d %d", &L, &N);
    for(i = 0; i < N; i++) {
        scanf("%d", &c);
        tmin = max(tmin, min(c, L + 1 - c));
        tmax = max(tmax, max(c, L + 1 - c));
    }
    printf("%d %d\n", tmin, tmax);
    return 0;
}