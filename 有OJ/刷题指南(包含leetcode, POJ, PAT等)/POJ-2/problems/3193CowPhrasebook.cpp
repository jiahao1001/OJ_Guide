#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
int m,n;
struct Trie{
    struct Node{
        Node *next[256];
        Node(){
            for(int i=0;i<256;i++) next[i] = NULL;
        }
    } *root;
    Trie(){
        root =  new Node();
    }
    void insert(char *phrase){
        int len = strlen(phrase);
        Node *p = root;
        for(int i=0;i<len;i++){
            char c = phrase[i];
            if(!p->next[c]) p->next[c] = new Node();
            p = p->next[c];
        }
    }
    int query(char *msg){
        int len = strlen(msg);
        Node *p = root;
        for(int i=0;i<len;i++){
            char c = msg[i];
            if(!p->next[c]) return 0;
            p = p->next[c];
        }
        return 1;
    }
} trie;
int main()
{
    char phrase[80];
    scanf("%d%d",&m,&n);
    gets(phrase);
    for(int i=0;i<m;i++){
        gets(phrase);
        trie.insert(phrase);
    }
    char msg[80];
    int cnt = 0;
    for(int i=0;i<n;i++){
        gets(msg);
        cnt+=trie.query(msg);
    }
    printf("%d\n",cnt);
    return 0;
}
