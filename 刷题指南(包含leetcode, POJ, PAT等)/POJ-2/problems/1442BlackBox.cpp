#include<stdlib.h>
#include<queue>
#include<iostream>
#include<stdio.h>
#include<assert.h>
using namespace std;
struct Treap{
    struct Node{
        int key, priority;
        Node *left, *right;
        int size;
        Node(int k,int p):key(k),priority(p),left(NULL),right(NULL),size(1){}
    }* root;
    Treap():root(NULL){}
    void left_rotate(Node *&x){
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        update(x);
        x = y;
    }
    int size(Node *root){
        if(!root) return 0;
        else return root->size;
    }
    void update(Node *root){
        root->size = 1 + size(root->left) + size(root->right);
    }
    void right_rotate(Node *&y){
        
        Node *x = y->left;
        y->left = x->right;
        x->right = y;
        update(y);
        y = x;
    }
    void insert(Node *&root, int key){
        if(!root) {
            root = new Node(key,rand());
            return;
        }
        if(key<root->key){
            insert(root->left,key);
            if(root->priority>root->left->priority)
                right_rotate(root);
        }else{
            insert(root->right,key);
            if(root->priority>root->right->priority)
                left_rotate(root);
        }
        update(root);
    }
    void insert(int key){
        insert(root,key);
    }
    int select(Node *root,int k){
        if(size(root->left)+1==k) return root->key;
        else if(size(root->left)+1>k) return select(root->left,k);
        else return select(root->right,k-size(root->left)-1);
    }
    int select(int k){
        assert(size(root)>=k);
        return select(root,k);
    }
};

const int M = 30001;
const int N = 30001;
int A[M];
int cnt[M];
int n,m,u;
int main()
{
    Treap treap;
    int k = 0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",A+i);
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        scanf("%d",&u);
        cnt[u] ++;
    }
    for(int i=1;i<=m;i++){
        treap.insert(A[i]);
        while(cnt[i]--) printf("%d\n",treap.select(++k));
    }
    
    
}
