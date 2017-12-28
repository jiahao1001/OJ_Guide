#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
using namespace std;
int A[50];
int n,r;
void reverse(int i,int j){
    j--;
    while(i<j){
        swap(A[i++],A[j--]);
    }
}
void shuffle(int p,int c){
    reverse(0,p-1);
    reverse(p-1,p+c-1);
    reverse(0,p+c-1);
}
int main()
{
    int p,c;
    while(scanf("%d%d",&n,&r),n||r){
        for(int i=0;i<n;i++) A[i] = n-i;
        //for(int i=0;i<n;i++) cout<<A[i]<<" ";
        for(int i=0;i<r;i++){
            scanf("%d%d",&p,&c);
            shuffle(p,c);
        }
        printf("%d\n",A[0]);
    }
    return 0;
}
