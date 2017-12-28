#include<iostream>
#include<stdio.h>
using namespace std;
int n,m;
int x,y;
long long v[36];
int bits[1<<18];
inline int countbits(long long x)
{
    return bits[x>>18]+bits[x&0x3ffff];
}
int check(int n,int cur,int sel,long long mask){
    if(countbits(mask)<n) return 0;
    if(sel==n) return 1;
    if(sel+36-cur<n) return 0;
    return check(n,cur+1,sel,mask) || check(n,cur+1,sel+1,mask&v[cur]);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<(1<<18);i++){
        int j=i;
        bits[i]=0;
        while(j) bits[i]+=(j&1),j>>=1;
    }
    //for(int i=0;i<20;i++)
    //  cout<<bits[i]<<endl;
    while(n--)
    {
        scanf("%d",&m);
        for(int i=0;i<36;i++) v[i]=0LL;
        for(int i=0;i<m;i++)
            scanf("%d%d",&x,&y),v[x-1]|=1LL<<(y-1);
        int k;
        for(k=1;k*k<=m && check(k,0,0,(1LL<<36)-1);k++);
        printf("%d\n",k-1);
    }
    return 0;
}
