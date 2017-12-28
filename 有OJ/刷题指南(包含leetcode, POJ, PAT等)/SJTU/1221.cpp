#include <cstdio>
#include <cstring>
using namespace std;
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
        clear(t->left);
        Delete_less_than(t->right,x);
        tree *tmp=t;
        t=t->right;
        delete tmp;
    } else Delete_less_than(t->left,x);
}
void Delete_greater_than(tree*& t,int x)
{
    if (t==NULL) return;
    if (t->data>x)
    {
        clear(t->right);
        Delete_greater_than(t->left,x);
        tree *tmp=t;
        t=t->left;
        delete tmp;
    } else Delete_greater_than(t->right,x);
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
void Delete_interval(tree*& t,int a,int b)
{
    while (t!=NULL && t->data>a && t->data<b) Delete(t);
    if (t!=NULL && t->left!=NULL) Delete_interval(t->left,a,b);
    if (t!=NULL && t->right!=NULL) Delete_interval(t->right,a,b);
}
bool Find_ith(const tree* t,int num)
{
    if (num>t->size) return false;
    int Left=(t->left!=NULL)?(t->left->size):0;
    if (num<=Left) return Find_ith(t->left,num);
    if (num==Left+1)
    {
        printf("%d\n",t->data);
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
    void ins(int x){Insert(root,x);}
    bool find(int x)
    {
        if (Find(root,x))
        {
            sort(root,x);
            return true;
        }else return false;
    }
    void del(int x)
    {
        if (find(x))
        {
            Delete(root);
        }
    }
    void delete_less_than(int x)
    {
        Delete_less_than(root,x);
    }
    void delete_greater_than(int x)
    {
        Delete_greater_than(root,x);
    }
    void delete_interval(int a,int b)
    {
        Delete_interval(root,a,b);
    }
    bool find_ith(int num)
    {
        markdown(root);
        return Find_ith(root,num);
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
    freopen("1221.in","r",stdin);
    bst b;
    int n,i,x,y,t;
    char token[20];
    scanf("%d",&n);
    for (i=0;i<n;++i)
    {
        scanf("%s",token);
        if (strcmp(token,"insert")==0)
        {
            scanf("%d",&x);
            b.ins(x);
        } else if (strcmp(token,"delete")==0)
        {
            scanf("%d",&x);
            b.del(x);
        } else if (strcmp(token,"delete_less_than")==0)
        {
            scanf("%d",&x);
            b.delete_less_than(x);
        } else if (strcmp(token,"delete_greater_than")==0)
        {
            scanf("%d",&x);
            b.delete_greater_than(x);
        } else if (strcmp(token,"delete_interval")==0)
        {
            scanf("%d %d",&x,&y);
            b.delete_interval(x,y);
        } else if (strcmp(token,"find")==0)
        {
            scanf("%d",&x);
            if (b.find(x)) printf("Y\n");else printf("N\n");
        } else if (strcmp(token,"find_ith")==0)
        {
            scanf("%d",&x);
            if (!b.find_ith(x)) printf("N\n");
        }
        //b.print();
    }
}
