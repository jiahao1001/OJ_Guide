#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
#include<algorithm>
using namespace std;
#define MAXN 65536
#define MAXLG 17
char A[MAXN];
struct entry {
    int nr[2], p;
} L[MAXN];
int P[MAXLG][MAXN], N, stp, cnt;
bool operator<(const entry &a, const entry &b)
{
    if(a.nr[0]==b.nr[0]) return a.nr[1]<b.nr[1];
    return a.nr[0]<b.nr[0];
}
void makesa()
{
    int i;
    for (N = strlen(A), i = 0; i < N; i ++)
        P[0][i] = A[i] - 'a';
    for (stp = 1, cnt = 1; cnt < N; stp ++, cnt <<= 1) {
        for (i = 0; i < N; i ++)
        {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
        sort(L, L + N);
        for (i = 0; i < N; i ++)
            P[stp][L[i].p] = i > 0
                && L[i].nr[0] == L[i - 1].nr[0]
                && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
    }
}
int rank1[MAXN], height[MAXN];
int sa[MAXN];
void calheight(){
    int i,j,k=0;
    for(int i=0;i<N;i++) rank1[i] = P[stp-1][i];
    for(int i=0;i<N;i++) sa[rank1[i]] = i;
    for(int i=0;i<N;i++){
        if(k) k--;
        if(rank1[i]==0){
            k = 0;
        }else{
            j = sa[rank1[i]-1];
            while(A[i+k]==A[j+k]) k++;
        }
        height[rank1[i]] = k;
    }
}
int start;
inline bool check(int len,int k){
    int re = 1;
    int ll = 0;
    int now = -1;
    for(int i=0;i<N;i++){
        if(height[i]>=len) re++,ll = max(ll,sa[i]);
        else re = 1,ll = sa[i];
        if(re>=k) now = max(now,ll);
    }
    if(now!=-1) start = now;
    return now!=-1;
}

int main()
{
    int m;
    while(scanf("%d",&m),m){
        scanf("%s",A);
        N = strlen(A);
        if(m==1){
            printf("%d %d\n",N,0);
            continue;
        }
        makesa();
        calheight();
        int l = 0, r = N+1;
        while(l+1<r){
            int mid = (l+r)>>1;
            if(check(mid,m)) l = mid;
            else r = mid;
        }
        if(l==0) printf("none\n");
        else{
            printf("%d %d\n",l,start);
        }
    }
    return 0;
}
