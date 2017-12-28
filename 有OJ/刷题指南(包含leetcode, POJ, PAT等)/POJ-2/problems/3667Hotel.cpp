#include<iostream>
#include<stdio.h>
#define MAXN 50010
using namespace std;
struct Node{
    int l,r,c,lc,rc,col;
    int len(){
        return r-l+1;
    }
};
Node tree[MAXN*3];
void build(int rt,int l,int r)
{
    tree[rt].l=l,tree[rt].r=r;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
}
void push_down(int rt){
    if(tree[rt].col!=-1){
        tree[rt<<1].col=tree[rt<<1|1].col=tree[rt].col;
        tree[rt<<1].lc=tree[rt<<1].rc=tree[rt<<1].c=tree[rt].col?(tree[rt<<1].r-tree[rt<<1].l+1):0;
        tree[rt<<1|1].lc=tree[rt<<1|1].rc=tree[rt<<1|1].c=tree[rt].col?(tree[rt<<1|1].r-tree[rt<<1|1].l+1):0;
        tree[rt].col=-1;
    }
}
void push_up(int rt)
{
    tree[rt].c=max(tree[rt<<1].c,max(tree[rt<<1|1].c,tree[rt<<1].rc+tree[rt<<1|1].lc));
    tree[rt].lc=tree[rt<<1].lc;
    if(tree[rt<<1].lc==tree[rt<<1].len()) tree[rt].lc += tree[rt<<1|1].lc;
    
    tree[rt].rc=tree[rt<<1|1].rc;
    if(tree[rt<<1|1].rc==tree[rt<<1|1].len()) tree[rt].rc += tree[rt<<1].rc;
}
void update(int rt,int l,int r,int col)
{
    if(l<=tree[rt].l && tree[rt].r<=r){
        tree[rt].col=col;
        tree[rt].lc=tree[rt].rc=tree[rt].c=col?(tree[rt].r-tree[rt].l+1):0;
        return;
    }
    push_down(rt);
    int mid=(tree[rt].l+tree[rt].r)>>1;
    if(l<=mid) update(rt<<1,l,r,col);
    if(mid+1<=r) update(rt<<1|1,l,r,col);
    push_up(rt);
}
int query(int rt,int d)
{
    if(tree[rt].c<d) return 0;
    if(tree[rt].lc>=d) return tree[rt].l;
    push_down(rt);
    if(tree[rt<<1].c>=d)
        return query(rt<<1,d);
    if(tree[rt<<1].rc+tree[rt<<1|1].lc>=d)
        return tree[rt<<1].r-tree[rt<<1].rc+1;
    return query(rt<<1|1,d);
}
int main()
{
    int N,M,op,d,s;
    scanf("%d%d",&N,&M);
    build(1,1,N);
    tree[1].lc=tree[1].rc=tree[1].c=N;
    tree[1].col=1;
    while(M--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&d);
            s=query(1,d);
            printf("%d\n",s);
            if(s)update(1,s,s+d-1,0);
        }
        else{
            scanf("%d%d",&s,&d);
            update(1,s,s+d-1,1);
        }
    }
    return 0;
}
