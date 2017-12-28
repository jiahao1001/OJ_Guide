#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int l[5000],r[5000],sum[5000];
int cnt;
int A[10000];
int f[10000];
int w[10000];
void init()
{
    for(int i=0;i<cnt;i++)
        f[i]=i,w[i]=0;
}
map<int,int> Hash;
int Find(int x)
{
    if(x==f[x]) return x;
    int r=Find(f[x]);
    w[x]^=w[f[x]];
    f[x]=r;
    return r;
}
int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    char s[10];
    for(int i=0;i<K;i++){
        scanf("%d %d %s",l+i,r+i,s);
        l[i]--;
        A[i<<1]=l[i],A[i<<1|1]=r[i];
        if(s[0]=='e') sum[i]=0;
        else sum[i]=1;
    }
    sort(A,A+2*K);
    cnt=unique(A,A+2*K)-A;
    for(int i=0;i<cnt;i++)
        Hash[A[i]]=i;
    init();
    int i=0;
    for(i=0;i<K;i++){
        int a=Hash[l[i]];
        int b=Hash[r[i]];
        int ra=Find(a),rb=Find(b);
        if(ra==rb){
            if((w[a]^w[b])!=sum[i]) break;
        }else{
            f[ra]=rb;
            w[ra]=w[a]^w[b]^sum[i];
        }
    }
    printf("%d\n",i);
    return 0;
}
