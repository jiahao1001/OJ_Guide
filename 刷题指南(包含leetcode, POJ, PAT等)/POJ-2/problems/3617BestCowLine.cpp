#include<iostream>
#include<stdio.h>
using namespace std;
const int N = 2010;
char line[N];

int test(int l,int r){
    for(int i=l+1,j=r-1;i<j;i++,j--){
        if(line[i]<line[j]) return l;
        if(line[i]>line[j]) return r;
     }
    return l;
}
char get(int &l,int &r)
{
    if(line[l]<line[r]) return line[l++];
    else if(line[l]>line[r]) return line[r--];
    else{
        if(test(l,r)==l) return line[l++];
        else return line[r--];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf(" %c",line+i);
    int l=0,r=n-1;
    for(int i=0;i<n;i++){
        printf("%c",get(l,r));
        if((i+1)%80==0 || i==n-1) printf("\n");
    }
    
    return 0;
}
