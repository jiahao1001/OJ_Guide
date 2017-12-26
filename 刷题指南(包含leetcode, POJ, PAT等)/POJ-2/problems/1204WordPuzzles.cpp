#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
#include<string.h>
using namespace std;
struct AC{
    struct Node{
        Node *son[26];
        Node *fail;
        char *word;
        int id;
        Node(){
            memset(son,0,sizeof(son));
            id = -1;
        }
    } *root, *q;
    AC(){
        root = new Node();
    }
    void insert(char *word,int id){
        int len = strlen(word);
        Node* r = root;
        for(int i=0;i<len;i++){
            if(r->son[word[i]-'a']==NULL)
                r->son[word[i]-'a'] = new Node();
            r = r->son[word[i]-'a'];
        }
        r->id = id;
        //r->word = strdup(word);
    }
    
    void build(){
        //phase I  goto(0,a) = 0 a does not label an edge out 
        for(int i=0;i<26;i++)
            if(!root->son[i]) root->son[i] = root;
        
        //phase II
        queue<Node*> Q;
        for(int i=0;i<26;i++){
            Node *q = root->son[i];
            if(q!=root) q->fail = root, Q.push(q);
        }
        
        while(!Q.empty()){
            Node * r = Q.front();
            Q.pop();
            for(int i=0;i<26;i++)
                if(r->son[i]){
                    Node *u = r->son[i];
                    Q.push(u);
                    Node *v = r->fail;
                    while(!v->son[i]) v = v->fail;
                    u->fail = v->son[i];
                    // u->cnt += u->fail->cnt;
                }
        }
    }
    void begin(){
        q = root;
    }
    int eat_char(char c){
        while(!q->son[c-'a']) q=q->fail;
        q = q->son[c-'a'];
        return q->id;
    }
    int query(char *word){
        int len = strlen(word);
        Node *q = root;
        for(int i=0;i<len;i++){
            while(!q->son[word[i]-'a']) q = q->fail;
            q = q->son[word[i]-'a'];
            if(q->id!=-1) printf("%s\n",q->word);
        }
        return 0;
    }
};
const int N = 1000;
const int C = 1001;
const int W = 1000;
char words[W][60];
char table[N][C];
int word_len[W];
int n,c,w;
int dx[8] ={-1,-1,0,1,1,1,0,-1};
int dy[8] ={0,1,1,1,0,-1,-1,-1};
//H A B
//G   C
//F E D
int ans_i[W],ans_j[W];
char dir[W];
AC ac;
inline void search(int i,int j){
    //start point is i,j, search eight dir
    for(int k=0;k<8;k++){
        int s = 0;
        int x,y;
        ac.begin();
        while(true){
            x = i+s*dx[k], y = j+s*dy[k];
            if(x<0 || x>=n || y<0 || y>=c) break;
            int id = ac.eat_char(table[x][y]);
            s++;
            if(id==-1) continue;
            //cout<<"found "<<id<<endl;
            dir[id] = 'A'+k;
            ans_i[id] = x-dx[k]*word_len[id];
            ans_j[id] = y-dy[k]*word_len[id];
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&c,&w);
    for(int i=0;i<n;i++) {
        scanf("%s",table[i]);
        for(int j=0;j<C;j++) table[i][j] = tolower(table[i][j]);
    }
    for(int i=0;i<w;i++){
        scanf("%s",words[i]);
        int len = strlen(words[i]);
        word_len[i] = len-1;
        for(int j=0;j<len;j++) words[i][j] = tolower(words[i][j]);
        ac.insert(words[i],i);
    }
    ac.build();
    for(int i=0;i<c;i++)
        search(0,i),search(n-1,i);
    for(int i=1;i<n-1;i++)
        search(i,0), search(i,c-1);
    for(int i=0;i<w;i++)
        printf("%d %d %c\n",ans_i[i],ans_j[i],dir[i]);
    
    return 0;
}
