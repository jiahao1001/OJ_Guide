#include <cstdio>
#include <queue>
using namespace std;
struct tree
{
    int data;
    tree *left,*right;
};
void insert(tree*& t,int val)
{
    if (t==NULL)
    {
        t=new tree;
        t->left=NULL;
        t->right=NULL;
        t->data=val;
    } else if (t->data == val) return;
    else if (t->data > val) insert(t->left,val);
    else insert(t->right,val);
}
void find(tree* h,int val)
{
    queue<char> res;
    res.push('*');
    while (h!=NULL)
    {
        if (h->data == val) break;
        else if (h->data < val)
        {
            h=h->right;
            res.push('r');
        } else
        {
            h=h->left;
            res.push('l');
        }
    }
    if (h==NULL) printf("Nothing.\n");
    else
    {
        while (!res.empty())
        {
            printf("%c",res.front());
            res.pop();
        }
        printf("\n");
    }
}
void remove(tree*& t,int val)
{
    if (t==NULL) return;
    else if (t->data == val)
    {
        tree *tmp;
        if (t->right == NULL)
        {
            tmp=t;
            t=t->left;
            delete tmp;
        } else if (t->right->left == NULL)
        {
            tmp=t->right;
            t->data=t->right->data;
            t->right=t->right->right;
            delete tmp;
        } else
        {
            for (tmp=t->right;tmp->left->left != NULL;tmp=tmp->left);
            t->data=tmp->left->data;
            tree *tt=tmp->left;
            tmp->left=tmp->left->right;
            delete tt;
        }
    } else if (t->data > val) remove(t->left,val);
    else remove(t->right,val);
}
int main()
{
    freopen("1560.in","r",stdin);
    int n,i,t;
    char f;
    scanf("%d",&n);
    tree *head=NULL;
    for (i=0;i<n;++i)
    {
        getchar();
        scanf("%c %d",&f,&t);
        if (f=='+') insert(head,t);
        else if (f=='-') remove(head,t);
        else find(head,t);
    }
}
