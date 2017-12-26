#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<limits.h>
using namespace std;
int id[1010];
int cnt = 0;
int M[201][201];
int A[201][201];
int B[201][201];
int N,T,S,E;
void add()
{
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++) B[i][j] = INT_MAX/2;
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++)
            for(int k=1;k<=cnt;k++)
                B[i][j] = min(B[i][j],A[i][k]+M[k][j]);
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++) A[i][j] = B[i][j];
}
void mult()
{
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++)
            B[i][j] = INT_MAX/2;
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++)
            for(int k=1;k<=cnt;k++)
                B[i][j] = min(B[i][j],M[i][k]+M[k][j]);
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++) M[i][j] = B[i][j];
}
int main()
{
    scanf("%d%d%d%d",&N,&T,&S,&E);
    if(!id[S]) id[S] = ++cnt;
    if(!id[E]) id[E] = ++cnt;
    for(int i=1;i<=200;i++)
        for(int j=1;j<=200;j++) M[i][j] = INT_MAX/2;
    int a,b,c;
    for(int i=0;i<T;i++){
        scanf("%d%d%d",&c,&a,&b);
        if(!id[a]) id[a]=++cnt;
        if(!id[b]) id[b]=++cnt;
        M[id[a]][id[b]] = M[id[b]][id[a]] = c;
    }
    int x=1;
    while(N){
        if(N&1){
            if(x!=1) add();
            else{
                for(int i=1;i<=cnt;i++)
                    for(int j=1;j<=cnt;j++) A[i][j] = M[i][j];
            }
            x++;
        }
        mult();
        N/=2;
    }
    printf("%d\n",A[id[S]][id[E]]);
    
}
