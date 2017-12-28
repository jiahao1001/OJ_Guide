#include <stdio.h>
struct tree
{
    int val;
    unsigned long long pos;
};
void ins(tree* t,int i,unsigned long long p,int* left,int* right)
{
    t[i].pos=p;
    if (left[i]!=-1) ins(t,left[i],2*p,left,right);
    if (right[i]!=-1) ins(t,right[i],2*p+1,left,right);
}
void qsort(tree* t,int l,int r)
{
    if (l>=r) return;
    int i=l,j=r,v=t[i].val;
    unsigned long long p=t[i].pos;
    while (i<j)
    {
        while ((i<j)&&(t[j].pos>=p)) --j;
        t[i].pos=t[j].pos;
        t[i].val=t[j].val;
        while ((i<j)&&(t[i].pos<=p)) ++i;
        t[j].pos=t[i].pos;
        t[j].val=t[i].val;
    }
    t[i].pos=p;
    t[i].val=v;
    qsort(t,l,i-1);
    qsort(t,i+1,r);
}
int main()
{
    int n,i,j,q,v;
    scanf("%d",&n);
    tree *t=new tree[n];
    int *left=new int[n],*right=new int[n];
    bool *p=new bool[n];
    for (i=0;i<n;++i) p[i]=true;
    for (i=0;i<n;++i)
    {
        scanf("%d %d %d",&left[i],&right[i],&(t[i].val));
        --left[i];
        --right[i];
        if (left[i]!=-1) p[left[i]]=false;
        if (right[i]!=-1) p[right[i]]=false;
    }
    for (i=0;i<n;++i) if (p[i]) break;
    ins(t,i,1,left,right);
    qsort(t,0,n-1);
    for (i=0;i<n;++i) printf("%d ",t[i].val);
    delete [] t;
    delete [] left;
    delete [] right;
    delete [] p;
}
