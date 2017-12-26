#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <climits>
using namespace std;
const int N = 100010;

struct Cow {
    int s, e;
    int id;
} cow[N], last;

bool operator<(const Cow& c1, const Cow& c2) {
    if (c1.e == c2.e) return c1.s < c2.s;
    return c1.e > c2.e;
}
int A[N];
int n;
int ans[N];

inline int lowbit(int x) {
    return x & (-x);
}

int sum(int n) {
    int total = 0;
    while (n) {
        total += A[n];
        n -= lowbit(n);
    }
    return total;
}

void add(int n, int d) {
    while (n<N) {
        A[n] += d;
        n += lowbit(n);
    }
}

int main() {
    while (scanf("%d", &n), n) {
        int s, e;
        memset(A,0,sizeof(A));
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &s, &e);
            s++, e++;
            cow[i].s = s, cow[i].e = e;
            cow[i].id = i;
        }
        sort(cow, cow + n);
        last.s = -1, last.e = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cow[i].s == last.s && cow[i].e == last.e) {
                cnt++;
            } else {
                cnt = 0;
                last.s = cow[i].s, last.e = cow[i].e;
            }
            ans[cow[i].id] = sum(cow[i].s) - cnt;
            add(cow[i].s, 1);
        }
        printf("%d", ans[0]);
        for (int i = 1; i < n; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;

}
