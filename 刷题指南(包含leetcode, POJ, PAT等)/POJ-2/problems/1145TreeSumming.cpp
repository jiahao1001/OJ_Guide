#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
using namespace std;
int s;
struct Node{
    int v;
    Node *left,*right;
    Node(int _v):v(_v),left(NULL),right(NULL){}
};
Node *parse_tree(){
    char c;
    while(c=getchar(),c!='('){}
    while(true){
        c=getchar();
        if(c==')'||c=='-'||isdigit(c)) break;
    }
    if(c==')') return NULL;
    int sign = 1;
    int v = 0;
    if(c=='-') sign = -1,scanf("%d",&v);
    else ungetc(c,stdin), scanf("%d",&v);
    v *= sign;
    Node *nd = new Node(v);
    nd->left = parse_tree();
    nd->right = parse_tree();
    while(true){
        c=getchar();
        if(c==')') break;
    }
    return nd;
}
bool dfs(Node *root,int s){
    if(!root->left && !root->right){
        if(s==root->v) return true;
        else return false;
    }
    return (root->left && dfs(root->left,s- (root->v))) || (root->right &&dfs(root->right,s-(root->v)));
}
void print(Node *root){
    if(!root) return;
    printf("%d ",root->v);
    print(root->left);
    print(root->right);
}
int main(){
    while(scanf("%d",&s)!=EOF){
        Node *root = parse_tree();
        //print(root);
        if(!root)printf("no\n");
        else{
            if(dfs(root,s)) printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}
