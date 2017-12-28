#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int N = 100000;
int n,m,k;
int len[N];
int oil[N];
inline bool check(int t){
    long long acc = ((long long)min(n,m))*t;
    long long need = 0;
    for(int i=0;i<n;i++){
        //k*a+b>=len, a+b==t   ka+t-a >= len   get a  k-1 a >= len/t*(k-1)
        if(len[i]<=t){
            oil[i]=0;
            continue;
        }
        int tt = ceil(1.0*(len[i]-t)/(k-1));
        if(tt>t) return false;
        need+=tt;
        oil[i]=tt;
    }
    if(acc<need) return false;
    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int l=0, r = 0;
        for(int i=0;i<n;i++)
            scanf("%d",len+i),r=max(r,len[i]);
        sort(len,len+n);
        scanf("%d%d",&m,&k);
        if(m==0 || k==1){
            printf("%d\n",r);
            continue;
        }
        if(m>n) m=n;
        while(l+1<r){
            int mid = (l+r)>>1;
            if(check(mid)) r = mid;
            else l = mid;
        }
        printf("%d\n",r);
    }
    return 0;
}
