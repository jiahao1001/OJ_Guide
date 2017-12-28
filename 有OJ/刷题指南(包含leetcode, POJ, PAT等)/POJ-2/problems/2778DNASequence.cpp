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
const int SZ = 4;
const int M = 100000;
const int MAX = 105;
int N;
int c2i(char);
struct AC{
    struct Node{
        Node *son[SZ];
        Node *fail;
        int danger;
        int id;
        Node(int i){
            memset(son,0,sizeof(son));
            danger = 0;
            id = i;
        }
    } *root;
    Node *A[105];
    int cnt;
    AC(){
        cnt = 0;
        root = new Node(cnt++);
        A[cnt-1] = root;
    }
    void insert(char *word){
        int len = strlen(word);
        Node* r = root;
        for(int i=0;i<len;i++){
            if(r->son[c2i(word[i])]==NULL){
                Node *p = new Node(cnt++);
                r->son[c2i(word[i])] = A[cnt-1] = p;
            }
            r = r->son[c2i(word[i])];
        }
        r->danger = 1;
        
    }
    
    void build(){
        //phase I  goto(0,a) = 0 a does not label an edge out 
        for(int i=0;i<SZ;i++)
            if(!root->son[i]) root->son[i] = root;
        
        //phase II
        queue<Node*> Q;
        for(int i=0;i<SZ;i++){
            Node *q = root->son[i];
            if(q!=root) q->fail = root, Q.push(q);
        }
        
        while(!Q.empty()){
            Node * r = Q.front();
            Q.pop();
            for(int i=0;i<SZ;i++)
                if(r->son[i]){
                    Node *u = r->son[i];
                    Q.push(u);
                    Node *v = r->fail;
                    while(!v->son[i]) v = v->fail;
                    u->fail = v->son[i];
                    u->danger |= v->son[i]->danger;
                    // u->cnt += u->fail->cnt;
                }else{ //This is the key step
                    r->son[i] = r->fail->son[i];
                }
        }
    }
};
struct Matrix{
    long long v[MAX][MAX];
    Matrix(){
        memset(v,0,sizeof v);
    }
    Matrix operator *(const Matrix B)
        {
            int i, j, k;
            Matrix C;
            for(i = 0; i < N; i ++)
                for(j = 0; j < N; j ++){
                    for(k = 0; k < N; k ++)
                    {
                        C.v[i][j] = (C.v[i][j] + v[i][k] * B.v[k][j])%M;
                    }
                    //C.v[i][j] %= M;
                }
            return C;
        }
};
int c2i(char c){
    
    switch(c){
    case 'A':return 0;
    case 'C':return 1;
    case 'T':return 2;
    case 'G':return 3;
    }
}
Matrix mtPow(Matrix A, int k){
    int i;
    Matrix B;
    for(i=0;i<N;i++)
        B.v[i][i] = 1;
    while(k){
        if(k&1) B = B*A;
        A = A*A;
        k>>=1;
    }
    return B;
    
}
int main()
{
    char str[15];
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    AC ac;
    while(m--){
        scanf("%s",str);
        ac.insert(str);
    }
    ac.build();
    N = ac.cnt;
    Matrix A;
    for(i=0;i<N;i++){
        if(ac.A[i]->danger) continue;
        for(int k=0;k<4;k++){
            j = ac.A[i]->son[k]->id;
            if(ac.A[j]->danger) continue;
            A.v[i][j] ++;
        }
    }
    
    A = mtPow(A,n);
    long long ans = 0;
    for(i=0;i<N;i++) ans+=A.v[0][i];
    printf("%lld\n",ans%M);
    return 0;
}
