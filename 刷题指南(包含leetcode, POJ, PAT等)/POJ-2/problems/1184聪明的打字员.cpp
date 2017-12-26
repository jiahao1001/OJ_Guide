#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
short v1[10000000];
short v2[10000000];
int goal;
int init;
int pass[7],cur;
int A[7],B[7];

inline void decode(int h,int *p){
    cur = h%10;
    h/=10;
    for(int i=6;i>=1;i--)
        p[i] = h%10, h/=10;
}
inline void decode(int h){
    decode(h,pass);
}
inline int encode(){
    int h = 0;
    for(int i=1;i<=6;i++)
        h = h*10+pass[i];
    h = h*10+cur;
    return h;
}
int to[10],cnt;
int A_mi,A_max,B_mi,B_max;
inline int search(queue<int>& Q,short *v1,short *v2,int k,int mi,int mx,int *P){
    mi = 0, mx=9;
    while(k--){
        int h = Q.front();
        int g,d = v1[h];
        Q.pop();
        cnt = 0;
        //swap0
        decode(h);
        if(pass[1]!=pass[cur]) swap(pass[1],pass[cur]),to[cnt++] = encode();
        
        decode(h);
        if(pass[cur]!=pass[6])swap(pass[cur],pass[6]),to[cnt++] = encode();
        
        //up
        decode(h);
        if(pass[cur]<mx) pass[cur]++,to[cnt++] = encode();
        decode(h);
        if(pass[cur]>mi) pass[cur]--,to[cnt++]= encode();
        
        decode(h);
        if((cur>1 && pass[cur]==P[cur]) || cur==6) cur--,to[cnt++] = encode();
        
        decode(h);
        if((cur<6 && pass[cur]==P[cur]) || cur==1) cur++,to[cnt++] = encode();
        
        for(int i=0;i<cnt;i++){
            int &g = to[i];
            if(v2[g]!=-1) return d+1+v2[g];
            else if(v1[g]!=-1)continue;
            v1[g] = d+1;
            Q.push(g);
        }
        
    }
    return -1;
}
inline int bfs(){
    queue<int> Q1;
    queue<int> Q2;
    memset(v1,-1,sizeof v1);
    memset(v2,-1,sizeof v2);
    v1[init] = 0;
    Q1.push(init);
    for(int i=1;i<=6;i++)
        v2[goal*10+i] = 0, Q2.push(goal*10+i);
    while(!Q1.empty() || !Q2.empty()){
        int k1 = Q1.size();
        int k2 = Q2.size();
        int t;
        if(k1<k2 && !k1) t = search(Q1,v1,v2,k1,B_mi,B_max,B);
        else t=search(Q2,v2,v1,k2,B_mi,B_max,A);
        if(t!=-1) return t;
    }
    return -1;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    decode(a*10,A);
    decode(b*10,B);
    A_mi = 10000000, B_mi = 10000000, A_max = 0, B_max = 0;
    for(int i=1;i<=6;i++) A_mi = min(A_mi,A[i]),A_max = max(A_max,A[i]);
    for(int i=1;i<=6;i++) B_mi = min(B_mi,B[i]), B_max = max(B_max,B[i]);
    if(a==b){
        printf("0\n");
        return 0;
    }
    goal = b;
    init = a*10+1;
    printf("%d\n",bfs());
    return 0;
}
