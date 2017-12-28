#include <cstdio>
#include <cstring>
using namespace std;
int leave=0,adjust=0,FFF;
struct tree
{
    int data,size;
    tree *left,*right;
    tree(int d){data=d;size=1;left=NULL;right=NULL;}
};
void Insert(tree*& t,int x)
{
    if (t==NULL)
    {
        t=new tree(x);
        return;
    }
    if (x<t->data) Insert(t->left,x);
    else Insert(t->right,x);
}
bool Find(const tree* t,int x)
{
    if (t==NULL) return false;
    if (x==t->data) return true;
    else if (x<t->data) return Find(t->left,x);
    else return Find(t->right,x);
}
void sort(tree*& t,int x)
{
    if (t->data==x) return;
    tree *tmp;
    if (t->data>x)
    {
        sort(t->left,x);
        tmp=t->left;
        t->left=tmp->right;
        tmp->right=t;
        t=tmp;
    } else
    {
        sort(t->right,x);
        tmp=t->right;
        t->right=tmp->left;
        tmp->left=t;
        t=tmp;
    }
}
void qxbl(tree* t)
{
    if (t==NULL) return;
    printf("%d ",t->data);
    qxbl(t->left);
    qxbl(t->right);
}
void zxbl(tree* t)
{
    if (t==NULL) return;
    zxbl(t->left);
    printf("%d ",t->data);
    zxbl(t->right);
}
void clear(tree*& t)
{
    if (t==NULL) return;
    if (t->left!=NULL) clear(t->left);
    if (t->right!=NULL) clear(t->right);
    delete t;
    t=NULL;
}
void markdown(tree*& t)
{
    if (t==NULL) return;
    t->size=1;
    if (t->left!=NULL)
    {
        markdown(t->left);
        t->size+=t->left->size;
    }
    if (t->right!=NULL)
    {
        markdown(t->right);
        t->size+=t->right->size;
    }
}
void Delete_less_than(tree*& t,int x)
{
    if (t==NULL) return;
    if (t->data<x)
    {
        ++leave;
        if (t->left!=NULL) leave+=t->left->size;
        clear(t->left);
        Delete_less_than(t->right,x);
        tree *tmp=t;
        t=t->right;
        delete tmp;
    } else Delete_less_than(t->left,x);
}
void Delete(tree*& t)
{
    if (t->left==NULL)
    {
        tree *tmp=t;
        t=t->right;
        delete tmp;
    } else if (t->right==NULL)
    {
        tree *tmp=t;
        t=t->left;
        delete tmp;
    } else
    {
        tree *p=t->right,*q=NULL;
        while (p->left!=NULL)
        {
            q=p;
            p=p->left;
        }
        if (q==NULL)
        {
            t->data=p->data;
            t->right=p->right;
            delete p;
        }else
        {
            t->data=p->data;
            q->left=p->right;
            delete p;
        }
    }
}
bool Find_ith(const tree* t,int num)
{
    if (num>t->size) return false;
    int Left=(t->left!=NULL)?(t->left->size):0;
    if (num<=Left) return Find_ith(t->left,num);
    if (num==Left+1)
    {
        FFF=t->data;
        printf("%d\n",t->data+adjust);
        return true;
    }
    return Find_ith(t->right,num-Left-1);
}
class bst
{
private:
    tree *root;
public:
    bst():root(NULL){}
    void ins(int x){Insert(root,x);sort(root,x);}
    void del(int x)
    {
        if (find(x))
        {
            Delete(root);
        }
    }
    bool find(int x)
    {
        if (Find(root,x))
        {
            sort(root,x);
            return true;
        }else return false;
    }
    void delete_less_than(int x)
    {
        markdown(root);
        Delete_less_than(root,x);
    }
    bool find_ith(int num)
    {
        markdown(root);
        if (root==NULL || root->size<num) return false;
        Find_ith(root,root->size+1-num);
        //sort(root,FFF);
        return true;
    }
    void print()
    {
        qxbl(root);
        printf("\n");
        zxbl(root);
        printf("\n");
    }
};
int main()
{
    freopen("1054.in","r",stdin);
    int n,min,i,j,k,x;
    char token;
    char t[10];
    bst b;
    scanf("%d %d",&n,&min);
    for (i=0;i<n;++i)
    {
        scanf("%s %d",t,&x);
        token=t[0];
        if (token=='I')
        {
            if (x>=min) b.ins(x-adjust);
            else ++leave;
        } else if (token=='A')
        {
            adjust+=x;
        } else if (token=='S')
        {
            adjust-=x;
            b.delete_less_than(min-adjust);
        } else if (token=='F')
        {
            if (!b.find_ith(x)) printf("-1\n");
        }
        //printf("%c %d  adjust:%d leave:%d\n",token,x,adjust,leave);
        //b.print();
    }
    printf("%d\n",leave);
}
