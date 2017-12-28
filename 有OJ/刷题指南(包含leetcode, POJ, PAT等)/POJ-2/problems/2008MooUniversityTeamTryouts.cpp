#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 1024;
struct node{
    int w,h,k;
} in[N];
int sort_h[N],sort_k[N];
int A,B,C,n,ch,cw,ans,box,slash,cnt;
bool cmp_h(const int& i1,const int& i2){
    return in[i1].h>in[i2].h;
}
bool cmp_k(const int& i1,const int& i2){
    return in[i1].k>in[i2].k;
}
void update(int h,int w){
    int k;
    for(;box<n && in[sort_h[box]].h>=h;box++)
        if(in[sort_h[box]].w>=w && in[sort_h[box]].w<=w+cw)
            cnt++;
    k = A*h + B*w +C;
    for(;slash<n && in[sort_k[slash]].k>k;slash++)
        if(in[sort_k[slash]].w >= w && in[sort_k[slash]].w<=w+cw)
            cnt--;
    ans = max(cnt,ans);
}
void calc(int i){
    int h,w;
    box = 0, slash = 0, cnt = 0;
    h = in[sort_h[i]].h;
    w = in[sort_h[i]].w;
    for(;i<n&&in[sort_h[i]].h>=h-ch;i++)
        if(in[sort_h[i]].w>=w && in[sort_h[i]].w<=w+cw)
            update(in[sort_h[i]].h,w);
}
int main()
{
    scanf("%d%d%d%d",&n,&A,&B,&C);
    cw = C/B;
    ch = C/A;
    for(int i=0;i<n;i++){
        scanf("%d%d",&in[i].h,&in[i].w);
        in[i].k = A*in[i].h + B*in[i].w;
        sort_h[i]=i;
        sort_k[i]=i;
    }
    sort(sort_h,sort_h+n,cmp_h);
    sort(sort_k,sort_k+n,cmp_k);
    for(int i=0;i<n;i++)
        calc(i);
    printf("%d\n",ans);
    return 0;
}
