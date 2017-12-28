#include<iostream>
#include<stdio.h>
#define MAXN 260
#define lson(x) ((x)<<1)
#define rson(x) ((x)<<1|1)
using namespace std;
int N,B,K;
struct SubNode{
    int u,d,min,max;
};
struct TreeNode
{
    int l,r;
    SubNode subtree[3*MAXN];
};
TreeNode tree[3*MAXN];
int A[MAXN][MAXN];
void buildsub(int t,int st,int u,int d)
{
    tree[t].subtree[st].u=u;
    tree[t].subtree[st].d=d;
    if(u==d){
        if(tree[t].l==tree[t].r)
            tree[t].subtree[st].min=tree[t].subtree[st].max=A[u][tree[t].l];
        else {
            tree[t].subtree[st].min=min(tree[lson(t)].subtree[st].min,tree[rson(t)].subtree[st].min);
            tree[t].subtree[st].max=max(tree[lson(t)].subtree[st].max,tree[rson(t)].subtree[st].max);
        }
        return;
    }
    int mid=(u+d)>>1;
    buildsub(t,lson(st),u,mid);
    buildsub(t,rson(st),mid+1,d);
    tree[t].subtree[st].min=min(tree[t].subtree[lson(st)].min,tree[t].subtree[rson(st)].min);
    tree[t].subtree[st].max=max(tree[t].subtree[lson(st)].max,tree[t].subtree[rson(st)].max);
    
}
int findsubmax(int t,int st,int u,int d)
{
    if(tree[t].subtree[st].u==u && tree[t].subtree[st].d==d){
        return tree[t].subtree[st].max;
    }
    int mid=(tree[t].subtree[st].u+tree[t].subtree[st].d)>>1;
    if(mid>=d) return findsubmax(t,lson(st),u,d);
    else if(mid+1<=u) return findsubmax(t,rson(st),u,d);
    else return max(findsubmax(t,lson(st),u,mid),findsubmax(t,rson(st),mid+1,d));
}
int findmax(int t,int l,int r,int u,int d)
{
    if(tree[t].l==l && tree[t].r==r){
        return findsubmax(t,1,u,d);
    }
    int mid = (tree[t].l+tree[t].r)>>1;
    if(mid>=r) return findmax(lson(t),l,r,u,d);
    else if(mid+1<=l) return findmax(rson(t),l,r,u,d);
    else return max(findmax(lson(t),l,mid,u,d),findmax(rson(t),mid+1,r,u,d));
    
}
int findsubmin(int t,int st,int u,int d)
{
    if(tree[t].subtree[st].u==u && tree[t].subtree[st].d==d){
        return tree[t].subtree[st].min;
    }
    int mid=(tree[t].subtree[st].u+tree[t].subtree[st].d)>>1;
    if(mid>=d) return findsubmin(t,lson(st),u,d);
    else if(mid+1<=u) return findsubmin(t,rson(st),u,d);
    else return min(findsubmin(t,lson(st),u,mid),findsubmin(t,rson(st),mid+1,d));
}
int findmin(int t,int l,int r,int u,int d)
{
    if(tree[t].l==l && tree[t].r==r){
        return findsubmin(t,1,u,d);
    }
    int mid = (tree[t].l+tree[t].r)>>1;
    if(mid>=r) return findmin(lson(t),l,r,u,d);
    else if(mid+1<=l) return findmin(rson(t),l,r,u,d);
    else return min(findmin(lson(t),l,mid,u,d),findmin(rson(t),mid+1,r,u,d));
}
void build(int t,int l,int r)
{
    tree[t].l=l,tree[t].r=r;
    if(l==r) {
        buildsub(t,1,1,N);
        return;
    }
    int mid=(l+r)>>1;
    build(lson(t),l,mid);
    build(rson(t),mid+1,r);
    buildsub(t,1,1,N);
}

inline int query(int row,int col,int size)
{
    return findmax(1,col,col+size-1,row,row+size-1)-findmin(1,col,col+size-1,row,row+size-1);
}
int main()
{
    scanf("%d%d%d",&N,&B,&K);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            scanf("%d",&A[i][j]);
    int row,col;
    build(1,1,N);
    for(int i=0;i<K;i++)
        scanf("%d%d",&row,&col),printf("%d\n",query(row,col,B));
    return 0;
}
