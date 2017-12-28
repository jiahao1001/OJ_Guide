#include <iostream>
using namespace std;
struct tree
{
    unsigned short data;
    tree* left;
    tree* right;
};
void insert(tree* &x,unsigned short& t)
{
    if (x==NULL)
    {
        x=new tree;
        x->data=t;
        x->left=NULL;
        x->right=NULL;
        return;
    }
    else if ((x->data)>t) insert((x->left),t);
    else insert((x->right),t);
}
void print(tree* x)
{
    if ((x->left)!=NULL) print(x->left);
    cout<<(x->data)<<' ';
    if ((x->right)!=NULL) print(x->right);
}
void clear(tree* &x)
{
    if ((x->left)!=NULL) clear(x->left);
    if ((x->right)!=NULL) clear(x->right);
    delete x;
}
int main()
{
    unsigned short n,i,t;cin>>n;
    tree* x=NULL;
    for (i=0;i<n;++i)
    {
        cin>>t;
        insert(x,t);
    }
    print(x);
    clear(x);
}
