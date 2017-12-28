#include<iostream>
#include<string.h>
#include<ctype.h>
#include<limits.h>
using namespace std;
struct Symbol{
    char type;//' ' means a number
    int value;
    Symbol(){}
    Symbol(char t,int v):type(t),value(v){}
}symbols[510];
Symbol rpn[510];
int cnt;
int size;
char equation[500];
int target;
char op[5]="+-*/";
Symbol st[510];
int S[510];
bool pred(char p1,char p2)
{
    if(p1=='(') return false;
    if(p1=='*'|| p1=='/'){
        return true;
    }
    if(p1=='+'||p1=='-'){
        return p2=='+'||p2=='-';
    }
    return false;
    
}
int calc(char c,int a,int b)
{
    switch(c){
    case '+':return a+b;
    case '-':return a-b;
    case '*':return a*b;
    case '/':return a/b;
    }
    return 0;
}
int evaluate(){
    int top = 0;
    cnt = 0;
    for(int i=0;i<size;i++){
        if(symbols[i].type==' ') rpn[cnt++] = symbols[i];
        else{
            if(!top) st[top++] = symbols[i];
            else{
                if(symbols[i].type=='(') st[top++] = symbols[i];
                else if(symbols[i].type==')'){
                    do{
                        rpn[cnt++] = st[--top];
                    }while(st[top].type!='(');
                    cnt --;
                }else{
                    while(top>0 && pred(st[top-1].type,symbols[i].type)) rpn[cnt++] = st[--top];
                    st[top++] = symbols[i];
                }
                
            }
        }
    }
    while(top>0) rpn[cnt++] = st[--top];
    top = 0;
    for(int i=0;i<cnt;i++){
        if(rpn[i].type==' ')
            S[top++] = rpn[i].value;
        else{
            if(rpn[i].type=='/' && S[top-1]==0) return INT_MAX;
            int d = calc(rpn[i].type,S[top-2],S[top-1]);
            top -= 2;
            S[top++] = d;
        }
    }
    /*
    for(int i=0;i<size;i++){
        if(symbols[i].type==' ') printf("%d",symbols[i].value);
        else printf("%c",symbols[i].type);
    }
    printf("%d\n",S[0]);
    */
    return S[0];
    
}
bool is_mark[110];
bool dfs(int i){
    if(i==size){
        //assert()
        if(evaluate()==target) return true;
        else return false;
    }
    if(is_mark[i]){
        for(int k=0;k<4;k++){
            symbols[i].type = op[k];
            if(dfs(i+1)) return true;
        }
        return false;
    }else{
        return dfs(i+1);
    }
    
    
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",equation);
        scanf("%d",&target);
        size = 0;
        int len = strlen(equation);
        int n = 0;
        int i=0;
        while(i<len)
        {
            n = 0;
            while(i<len && isdigit(equation[i])) n = n*10+(equation[i++]-'0');
            if(n)
                symbols[size++] = Symbol(' ',n);
            
            if(i<len) symbols[size++] = Symbol(equation[i++],0);
        }
        memset(is_mark,0,sizeof(is_mark));
        for(int i=0;i<size;i++)
            if(symbols[i].type=='?') is_mark[i] = 1;
        
        if(dfs(0)) printf("yes\n");
        else printf("no\n");
        
    }
    return 0;
}
