#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
const int N = 10000000;
int n;
int book[N],A[N],m;
int cnt[N];

inline int id(int x){
    return lower_bound(A,A+m,x)-A;
}//return the id of an idea [0,cnt)
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",book+i);
    for(int i=0;i<n;i++) A[i] = book[i];
    sort(A,A+n);
    m = unique(A,A+n)-A;
    int l,r;
    l=-1, r=0;
    int best = INT_MAX;
    int idea = 0;
    while(r<n){
        while(idea<m&&r<n){
            if(!cnt[id(book[r])]) idea++;
            cnt[id(book[r++])]++;
        }
        
        while(cnt[id(book[l+1])]>1) cnt[id(book[++l])]--;
        //printf("(%d,%d)\n",l,r);
        if(idea==m)
            best = min(best,r-l-1);
        cnt[id(book[++l])]--, idea--;
    }
    printf("%d\n",best);
    return 0;
}
