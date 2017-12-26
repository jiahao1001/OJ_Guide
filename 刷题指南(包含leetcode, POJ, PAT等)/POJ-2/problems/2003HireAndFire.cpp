#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
string cmd,x,y;
struct Node{
    string name;
    Node *son,*sibling;
    Node *pre;
    Node(string x):name(x),son(NULL),sibling(NULL),pre(NULL){}
};
struct Tree{
    map<string,Node*> loc;
    Node *root;
    Tree(){root=NULL;}
    void ceo(string x){
        root = new Node(x);
        loc[x] = root;
    }
    void hire(string x,string y){
        Node *p = loc[x];
        if(!p->son){
            p->son = new Node(y);
            loc[y] = p->son;
            p->son->pre = p;
            return;
        }
        Node *q = p->son;
        while(q->sibling) q = q->sibling;
        q->sibling = new Node(y);
        q->sibling->pre = q;
        loc[y] = q->sibling;
    }
    void fire(string x){
        Node *p = loc[x];
        Node *q = p->sibling;
        while(p->son){
            Node *y = p->son->sibling;
            p->son->sibling = q;
            if(q) q->pre = p->son;
            q = y;
            p = p->son;
        }
        p->son = q;
        if(q) q->pre = p;
        p = loc[x];
        q = p->son;
        if(p==root){
            root = q;
        }else{
            if(p->pre->son ==p) {
                p->pre->son = q;
                if(q)q->pre = p->pre;
            }
            else {
                p->pre->sibling =q;
                if(q)q->pre = p->pre;
            }
        }
        loc.erase(x);
        
    }
    void print(int d,Node *rt){
        Node *p = rt;
        while(p){
            cout<<string(d,'+')<<p->name<<endl;
            if(p->son) print(d+1,p->son);
            p = p->sibling;
        }
    }
    void print(){
        if(root)
            print(0,root);
        printf("------------------------------------------------------------\n");
    }
}tree;
int main()
{
    cin>>x;
    tree.ceo(x);
    while(cin>>cmd){
        if(cmd=="print"){
            tree.print();
        }else if(cmd=="fire"){
            cin>>x;
            tree.fire(x);
        }else{
            cin>>x>>y;
            x = cmd;
            tree.hire(x,y);
        }
    }
    return 0;
}
