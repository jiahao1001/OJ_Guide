#include<map>
#include<set>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
const int M = 105943;
set<int> v;
char word[5000][40];

int n,tot;
struct Node{
    Node *next[26];
    bool final;
    Node(){
        for(int i=0;i<26;i++)
            next[i] = NULL;
        final = false;
    }
};
map<int,vector<Node*> > htable;
void insert(Node *root,char *s){
    int len = strlen(s);
    Node *p = root;
    for(int i=0;i<len;i++){
        int j = s[i]-'a';
        if(p->next[j]==NULL) p->next[j] = new Node();
        p = p->next[j];
    }
    p->final = true;
}
bool same(Node *r1, Node *r2){
    if(!r1 && !r2) return true;
    if(!r1 || !r2) return false;
    if(r1->final!=r2->final) return false;
    for(int i=0;i<26;i++)
        if(!same(r1->next[i],r2->next[i])) return false;
    return true;
    
}
void push(int h,Node *root){
    //add root to hash table, if not duplicate, tot++
    if(!htable.count(h)){
        htable[h] = vector<Node*>();
    }
    int size = htable[h].size();
    vector<Node*> &v = htable[h];
    for(int i=0;i<size;i++){
        if(same(v[i],root)) return;
    }
    tot++;
    v.push_back(root);
}
int dfs(Node *root){
    int h = 0;
    for(int i=0;i<26;i++)
        if(root->next[i]){
            h = (h+(dfs(root->next[i])*27+i+1))%M;
        }
    push(h,root);
    return h;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",word[i]);
    Node *root = new Node();
    for(int i=0;i<n;i++)
        insert(root,word[i]);
    tot = 0;
    dfs(root);
    printf("%d\n",tot);
    return 0;
}
