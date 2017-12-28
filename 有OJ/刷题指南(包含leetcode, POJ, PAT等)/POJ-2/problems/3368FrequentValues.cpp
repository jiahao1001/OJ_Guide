#include<iostream>
#include<map>
#include<set>
#include<string>
#include <vector>
#include <stdlib.h>
#include <climits>
#include <utility>
#include <stdio.h>
#include <assert.h>
#include <stack>
#include <string.h>
#include <queue>
using namespace std;
#define lson (rt<<1)
#define rson ((rt<<1)|1)
const int N = 100010;
int n, q;
int u, v;
int A[N];

struct Node {
    int l, r;
    int lmax, mmax, rmax;
    int lp, rp;
} T[N << 2];

void push_up(int rt, int m) {
    T[rt].mmax = max(T[lson].mmax, T[rson].mmax);
    T[rt].lp = T[lson].lp;
    T[rt].rp = T[rson].rp;
    T[rt].lmax = T[lson].lmax;
    T[rt].rmax = T[rson].rmax;
    if (T[lson].rp == T[rson].lp) {
        T[rt].mmax = max(T[rt].mmax, T[lson].rmax + T[rson].lmax);
        if (T[lson].lmax == m - (m / 2)) T[rt].lmax += T[rson].lmax;
        if (T[rson].rmax == m / 2) T[rt].rmax += T[lson].rmax;
    }
}

void build(int rt, int l, int r) {
    T[rt].l = l;
    T[rt].r = r;
    if (l == r) {
        T[rt].lp = T[rt].rp = A[l];
        T[rt].lmax = T[rt].rmax = T[rt].mmax = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    push_up(rt, r - l + 1);
}

int query(int rt, int l, int r) {
    if (l <= T[rt].l && r >= T[rt].r) return T[rt].mmax;
    int ret = 0;
    int m = (T[rt].l + T[rt].r) / 2;
    if (l <= m) ret = max(ret, query(lson, l, r));
    if (r >= m + 1) ret = max(ret, query(rson, l, r));
    if (T[lson].rp == T[rson].lp && l <= m && r > m) {
        int x = T[lson].rmax;
        int y = T[rson].lmax;
        if (m - x + 1 <= l - 1) x = m - l + 1;
        if (m + y >= r + 1) y = r - m;
        ret = max(ret, x + y);
    }
    return ret;

}

int main() {
    while (scanf("%d", &n), n) {
        scanf("%d", &q);
        for (int i = 1; i <= n; i++)
            scanf("%d", A + i);
        build(1, 1, n);
        for (int i = 1; i <= q; i++) {
            scanf("%d%d", &u, &v);
            printf("%d\n", query(1, u, v));
        }
    }
    return 0;
}
