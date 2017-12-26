#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
#include<float.h>
#include<math.h>
#include<sstream>
#include<stdlib.h>
#include<limits.h>
#include<string>
#include<assert.h>
#include<numeric>
#include<map>
using namespace std;
const int N = 1000010;
const int M = 1000010;

int wa[N], wb[N], wv[N], wss[M];

int cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++) wss[i] = 0;
    for (i = 0; i < n; i++) wss[x[i] = r[i]]++;
    for (i = 1; i < m; i++) wss[i] += wss[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--wss[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p) {
        for (p = 0, i = n - j; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < n; i++) wv[i] = x[y[i]];
        for (i = 0; i < m; i++) wss[i] = 0;
        for (i = 0; i < n; i++) wss[wv[i]]++;
        for (i = 1; i < m; i++) wss[i] += wss[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--wss[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
    return;
}
int rank[N], height[N];
//height[i] = lcp(sa[i-1],sa[i])
void calheight(int *r, int *sa, int n) {
    int i, j, k = 0;
    for (i = 0; i < n; i++) rank[sa[i]] = i;
    for (i = 0; i < n; i++){
        if(k>0) k--;
        if(!rank[i]) continue;
        for (j = sa[rank[i] - 1]; i+k<n && j+k<n && r[i + k] == r[j + k]; k++);
        height[rank[i]] = k;
    }
    return;
}

int n,k;
int r[N],sa[N];
bool check(int len){
    int i=1;
    int cnt = 1;
    while(i<n){
        while(i<n && height[i]>=len) i++,cnt++;
        if(cnt>=k) return true;
        cnt = 1;
        while(i<n && height[i]<len) i++;
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",r+i),r[i]++;
    r[n++]=0;
    da(r,sa,n,M-1);
    calheight(r,sa,n);
    int l = 0, r = n;
    int mid;
    while(l+1<r){
        mid = (l+r)>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    printf("%d\n",l);
    return 0;
}
