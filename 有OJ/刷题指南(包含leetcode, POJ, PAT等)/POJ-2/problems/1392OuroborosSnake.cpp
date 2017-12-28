#include<iostream>
using namespace std;
int b[16][1<<15];
int v[1<<15];
int vv[1<<15];
int mask;
bool dfs(int n,int i,int x){
    if(i==(1<<n)){
        memset(vv,0,sizeof vv);
        for(int j=0;j<n-1;j++){
            x = (x&mask)<<1;
            if(v[x] || vv[x]) return false;
            vv[x] = 1;
        }
        return true;
    }
    for(int d=0;d<=1;d++){
        if(!v[((x&mask)<<1)+d]){
            b[n][i] = d;
            v[((x&mask)<<1)+d] = 1;
            if(dfs(n,i+1,((x&mask)<<1)+d)) return true;
            v[((x&mask)<<1)+d] = 0;
        }
    }
    return false;
}
void compute(int n){
    memset(v,0,sizeof v);
    v[0] = 1;
    for(int i=0;i<n;i++) b[n][i] = 0;
    mask = ((1<<n)-1)^(1<<(n-1));
    dfs(n,n,0);
}
int main()
{
    int n,k;
    for(int i=1;i<=15;i++){
        compute(i);
    }
    while(cin>>n>>k,n||k){
        int x = 0;
        for(int i=k;i<k+n;i++){
            x = (x<<1)+b[n][i%(1<<n)];
        }
        printf("%d\n",x);
    }
    return 0;
}
