#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 100010;
#define lson  (rt<<1)
#define rson  ((rt<<1)|1)
struct Node{
    int l,r,sum,lmax,rmax,max,min,lmin,rmin;
}tree[4*N];
int A[N];
void update(int rt){
    //update sum, lmax, rmax, max, lmin, rmin, min
    tree[rt].sum = tree[rson].sum + tree[lson].sum;
    tree[rt].max = max(tree[lson].max,max(tree[rson].max,tree[lson].rmax+tree[rson].lmax));
    tree[rt].min = min(tree[lson].min,min(tree[rson].min,tree[lson].rmin+tree[rson].lmin));
    tree[rt].lmax = max(tree[lson].lmax,tree[lson].sum+tree[rson].lmax);
    tree[rt].rmax = max(tree[rson].rmax, tree[rson].sum+tree[lson].rmax);
    tree[rt].lmin = min(tree[lson].lmin,tree[lson].sum+tree[rson].lmin);
    tree[rt].rmin = min(tree[rson].rmin, tree[rson].sum+tree[lson].rmin);
    
}
void build(int rt,int l,int r){
    tree[rt].l = l, tree[rt].r = r;
    if(l==r){
        tree[rt].sum = tree[rt].lmax = tree[rt].rmax = tree[rt].max = A[l];
        tree[rt].lmin = tree[rt].rmin = tree[rt].min = A[l];
        return;
    }
    int mid = (l+r)>>1;
    build(lson,l,mid);
    build(rson, mid+1,r);
    update(rt);
}
void modify(int rt,int i,int x){
    int l=tree[rt].l, r = tree[rt].r;
    if(l==r){
        tree[rt].sum = tree[rt].lmax = tree[rt].rmax = tree[rt].max = x;
        tree[rt].lmin = tree[rt].rmin = tree[rt].min = x;
        return;
    }
    int mid = (l+r)>>1;
    if(i<=mid) modify(lson,i,x);
    else modify(rson,i,x);
    update(rt);
    
}
int query(int i,int x){
    int rt = 1;
    modify(1,i,x);
    int ans = max(tree[rt].max,tree[rt].lmax+tree[rt].rmax);
    if(tree[rt].sum<=ans) return tree[rt].sum-tree[rt].min;
    else return ans;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",A+i);
    }
    int a,b;
    build(1,0,n-1);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        a--;
        printf("%d\n",query(a,b));
    }
    
    
    return 0;
}
