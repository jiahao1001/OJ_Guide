#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int A[1000000];
int T[1000000];
long long cnt;
void mergesort(int p,int r)
{
    if(p==r)return;
    int mid=(p+r)>>1;
    mergesort(p,mid);
    mergesort(mid+1,r);
    long long local=0;
    int i=p,j=mid+1;
    for(int k=p;k<=r;k++){
        if(i<=mid && j<=r){
            if(A[i]> A[j]) local++,T[k]=A[j++];
            else cnt+=local, T[k]=A[i++];
        }
        else if(i<=mid) cnt+=local,T[k]=A[i++];
        else T[k]=A[j++];
    }
    for(int k=p;k<=r;k++)
        A[k]=T[k];
    
}
struct Road{
    int w,e;
};
bool operator<(const Road &r1, const Road &r2){
    if(r1.w==r2.w) return r1.e<r2.e;
    else return r1.w<r2.w;
}
Road roads[1000000];

int main()
{
    int t;
    scanf("%d",&t);
    for(int q=1;q<=t;q++){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<k;i++)
            scanf("%d%d",&roads[i].w,&roads[i].e);
        sort(roads,roads+k);
        for(int i=0;i<k;i++)
            A[i]=roads[i].e;
        cnt=0;
        mergesort(0,k-1);
        printf("Test case %d: %lld\n",q,cnt);
    }
}
