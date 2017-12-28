#include <cstdio>
struct Tree
{
    int data;
    Tree *left,*right;
};
void insert(Tree* &t,int value)
{
    if (t==NULL)
    {
        t=new Tree;
        t->data=value;
        t->left=NULL;
        t->right=NULL;
    } else
    {
        if (t->data == value) return;
        else if (t->data > value) insert(t->left,value);
        else insert (t->right,value);
    }
}
bool search(Tree* t,int value)
{
    if (t==NULL) return false;
    if (t->data == value) return true;
    if (t->data > value) return search(t->left,value);
    if (t->data < value) return search(t->right,value);
}
int main()
{
    int n,i,t;
    Tree *head=NULL;
    scanf("%d",&n);
    for (i=0;i<n;++i)
    {
        scanf("%d",&t);
        insert(head,t);
    }
    scanf("%d",&n);
    for (i=0;i<n;++i)
    {
        scanf("%d",&t);
        if (search(head,t)) printf("Y\n");else printf("N\n");
    }
}
