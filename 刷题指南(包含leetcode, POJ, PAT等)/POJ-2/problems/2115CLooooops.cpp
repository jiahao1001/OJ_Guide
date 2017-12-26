#include <iostream>
using namespace std;

long long ext_gcd(long long a,long long b,long long &x,long long &y){
    long long t,ret;
    if(!b){
        x=1,y=0;
        return a;
    }
    ret=ext_gcd(b,a%b,x,y);
    t=x,x=y,y=t-a/b*y;
    return ret;
}
long long modular_linear(long long a,long long b,long long n){
    long long d,e,x,y;
    d=ext_gcd(a,n,x,y);
    b%=n;
    if(b%d)
        return -1;
    e=x*(b/d)%n+n;
    return e%(n/d);
}
int main(){
    long long d,a,b,c,k;
    while(scanf("%lld %lld %lld %lld",&a,&b,&c,&k),a||b||c||k){
        d=modular_linear(c,(b-a),1LL<<k);
        if(d==-1)
            puts("FOREVER");
        else
            printf("%lld\n",d);
    }
    return 0;
}
