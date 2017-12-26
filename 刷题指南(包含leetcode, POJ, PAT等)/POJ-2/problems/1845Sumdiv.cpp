#include<iostream>
using namespace std;
const int MOD = 9901;
const int N = 10000;
typedef long long LL;
int A,B;
int p[N],q[N];
LL pow(LL p, LL n){
    LL sum = 1;
    while(n>0){
        if(n&1) sum = (sum*p)%MOD;
        n>>=1;
        p = p*p % MOD;
    }
    return sum;
}
LL sum(LL p, LL n){
    // 1+p+p^2...+p^n % mod
    if(n==0) return 1;
    if(n&1) return ((1+pow(p,n/2+1))*sum(p,n/2)) % MOD;
    else return ((1+pow(p,n/2+1))*sum(p,n/2-1)+pow(p,n/2))%MOD;
    
}
int main(){
    int i,k;
    scanf("%d%d",&A,&B);
    for(k=0,i=2;i*i<=A;i++){
        if(A%i==0){
            p[k] = i;
            while(A%i==0) q[k]++,A/=i;
            k++;
        }
    }
    if(A!=1) p[k] = A, q[k++]= 1;
    
    int ans = 1;
    for(int i=0;i<k;i++)
        ans = ans*(sum(p[i],q[i]*B)%MOD) % MOD;
    printf("%d\n",ans);
    return 0;
}
