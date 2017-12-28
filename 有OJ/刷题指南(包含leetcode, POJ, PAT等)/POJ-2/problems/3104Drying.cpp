
#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int n,a[100000];
int k;
inline bool check(int t){
    // use t can dry all?
    long long cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i]<t) continue;
        cnt += (a[i]-t+k-1)/k;
    }
    return cnt<=t;
}
int main(){
    scanf("%d",&n);
    int l=0,r = 0;
    for(int i=0;i<n;i++) scanf("%d",a+i), r = max(r,a[i]);
    scanf("%d",&k);
    k--;
    if(!k){
        printf("%d\n",r);
        return 0;
    }
    int mid;
    while(l+1<r){
        mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l=mid;
    }
    printf("%d\n",r);
    return 0;
}
