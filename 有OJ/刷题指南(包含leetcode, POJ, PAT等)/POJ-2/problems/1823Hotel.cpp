#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int N = 16010;
int n,p;
int cmd;
int x,m;
struct Node{
    int l,r;
    int lmax,rmax,max;
    int L;
    int c;
} tr[N<<2];
void update(int rt){
    int lson = rt<<1, rson = rt<<1|1;
    tr[rt].lmax = tr[lson].lmax;
    if(tr[lson].lmax==tr[lson].L) tr[rt].lmax+=tr[rson].lmax;
    tr[rt].rmax = tr[rson].rmax;
    if(tr[rson].rmax == tr[rson].L) tr[rt].rmax += tr[lson].rmax;
    tr[rt].max = max(tr[lson].rmax+tr[rson].lmax,max(tr[lson].max,tr[rson].max));
}
void fill(int rt,int c){
    tr[rt].c = c;
    tr[rt].lmax = tr[rt].rmax = tr[rt].max = (c==1?0:tr[rt].L);
}
void push_down(int rt){
    if(tr[rt].c==0) return;
    fill(rt<<1,tr[rt].c);
    fill(rt<<1|1,tr[rt].c);
    tr[rt].c = 0;
}
void build(int rt,int l,int r){
    if(l>r) return;
    tr[rt].c = 0;
    tr[rt].l=l,tr[rt].r = r;
    tr[rt].lmax =tr[rt].rmax = tr[rt].max = r-l+1;
    tr[rt].L = r-l+1;
    if(l==r) return;
    int mid = (l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
}
void insert(int c,int rt,int l,int r){
    //1 enter guest -1, release guest
    if(l<=tr[rt].l && r>=tr[rt].r){
        tr[rt].c = c;
        if(c==1) tr[rt].max = tr[rt].lmax = tr[rt].rmax = 0;
        else tr[rt].max = tr[rt].lmax = tr[rt].rmax = tr[rt].L;
        return;
    }
    push_down(rt);
    int mid = (tr[rt].l+tr[rt].r)>>1;
    if(l<=mid) insert(c,rt<<1,l,r);
    if(r>=mid+1) insert(c,rt<<1|1,l,r);
    update(rt);
}
int main()
{
    scanf("%d%d",&n,&p);
    build(1,1,n);//all available
    tr[1].c = -1;
    for(int i=0;i<p;i++){
        scanf("%d",&cmd);
        if(cmd<3) scanf("%d%d",&x,&m);
        if(cmd==1){
            insert(1,1,x,x+m-1);
        }else if(cmd==2){
            insert(-1,1,x,x+m-1);
        }else printf("%d\n",tr[1].max);
    }
    return 0;
}
