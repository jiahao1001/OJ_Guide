#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
struct Node{
    char c;
    Node *l,*r;
    Node(char _c):c(_c),l(NULL),r(NULL){}
};
struct Tree{
    Node *root;
    Tree(){
        root = NULL;
    }
    void insert(char c){
        if(!root){
            root = new Node(c);
            return;
        }
        Node* p=root;
        Node* prev = root;
        while(p){
            prev = p;
            if(p->c>c) p=p->l;
            else p=p->r;
        }
        if(prev->c>c) prev->l = new Node(c);
        else prev->r = new Node(c);
    }
    void insert_leaves(string s){
        for(int i=0;i<s.size();i++)
            insert(s[i]);
    }
    void print(Node *rt){
        if(!rt) return;
        printf("%c",rt->c);
        print(rt->l);
        print(rt->r);
    }
    void print(){
        print(root);
        printf("\n");
    }
};
vector<string> leaves;
int main()
{
    string s;
    while(true){
        leaves.clear();
        while(cin>>s,s!="$" && s!="*")leaves.push_back(s);
        Tree tree;
        for(int i=leaves.size()-1;i>=0;i--){
            tree.insert_leaves(leaves[i]);
        }
        tree.print();
        if(s=="$")break;
    }
    return 0;
}
