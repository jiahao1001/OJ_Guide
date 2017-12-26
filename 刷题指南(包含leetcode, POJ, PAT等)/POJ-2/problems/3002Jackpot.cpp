#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int B = 1e9;
long long p[20];
long long gcd(long long x,long long y){
    if(!y) return x;
    return gcd(y,x%y);
}
long long lcm(long long a,long long b){
    long long g= gcd(a,b);
    return a/g*b;
}
int main(){
    int n;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lld",p+i);
        long long ans = p[0];
        for(int i=1;i<n;i++){
            ans = lcm(ans,p[i]);
            if(ans>B) break;
        }
        if(ans>B) printf("More than a billion.\n");
        else printf("%lld\n",ans);
        
    }
    return 0;
}
