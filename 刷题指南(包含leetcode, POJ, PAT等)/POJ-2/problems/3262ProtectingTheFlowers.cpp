#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct Cow{
    int d,t;
} cows[100000];
bool operator<(const Cow &c1, const Cow& c2){
    return c1.d*c2.t > c2.d * c1.t;
}
long long sum[100100];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&cows[i].t,&cows[i].d);
    }
    sort(cows,cows+n);
    sum[n] = 0;
    for(int i=n-1;i>=0;i--) sum[i] = sum[i+1]+cows[i].d;
    long long ans = 0;
    for(int i=0;i<n;i++)
        ans += cows[i].t*2*sum[i+1];
    printf("%lld\n",ans);
}
