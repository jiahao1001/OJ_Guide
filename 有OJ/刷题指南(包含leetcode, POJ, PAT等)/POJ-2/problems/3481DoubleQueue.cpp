#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define MAXN 100010
using namespace std;
struct Node{
    int key,val,pri;
    int ch[2];
    void set(int x, int y, int z) {
        key = x, val = y, pri = z, ch[0]=ch[1]=-1;
    }
} T[MAXN];
int cnt=0,rt=-1;
void rotate(int &x,int f)
{
    int y=T[x].ch[f];
    T[x].ch[f]=T[y].ch[!f];
    T[y].ch[!f]=x;
    x=y;
}
void insert(int &x,int key,int val){
    if(x==-1) T[x=cnt++].set(key,val,rand());
    else{
        int f=key>T[x].key;
        insert(T[x].ch[f],key,val);
        if(T[x].pri>T[T[x].ch[f]].pri) rotate(x,f);
    }
}
void del(int &x,int key)
{
    if ( T[x].key == key ) {
        if ( T[x].ch[0]==-1 || T[x].ch[1]==-1 ) {
            if ( T[x].ch[0]==-1 ) x = T[x].ch[1];
            else x = T[x].ch[0];
        } else {
            int f = T[T[x].ch[0]].pri > T[T[x].ch[1]].pri;
            rotate (x,f);
            del(T[x].ch[!f], key);
        }
    } else {
        int f = T[x].key < key;
        del(T[x].ch[f], key);
    }     
}
int get(int x,int f){
    if(x==-1) return -1;
    while(T[x].ch[f]!=-1) x=T[x].ch[f];
    return x;
}

int cmd,k,p;

int main()
{
    while(scanf("%d",&cmd),cmd){
        if(cmd==2){
            int x=get(rt,1);
            if(x!=-1) printf("%d\n",T[x].val),del(rt,T[x].key);
            else printf("0\n");
            //get largest 
        }else if(cmd==3){
            //get lowest
            int x=get(rt,0);
            if(x!=-1) printf("%d\n",T[x].val),del(rt,T[x].key);
            else printf("0\n");
        }else{
            scanf("%d%d",&k,&p);
            //insert key=p, val=k;
            insert(rt,p,k);
        }
    }
    return 0;
}
