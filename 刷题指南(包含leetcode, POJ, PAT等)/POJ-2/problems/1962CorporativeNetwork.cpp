#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<set>
#include<string.h>
#include<queue>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;
const int N = 20010;
int n;
int f[N],d[N];
void union_set(int x,int y){
    f[x] = y;
    d[x] = abs(x-y) % 1000;
}
int find_set(int x){
    if(f[x]==x) return x;
    int r = find_set(f[x]);
    d[x] = d[x] + d[f[x]];
    f[x] = r;
    return r;
}
int main(){
    int t,I,J;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) f[i]=i,d[i] = 0;
        char cmd;
        while(scanf(" %c",&cmd),cmd!='O'){
            scanf("%d",&I);
            if(cmd=='I') scanf("%d",&J);
            if(cmd=='E'){
                find_set(I);
                printf("%d\n",d[I]);
            }else{
                union_set(I,J);
            }
        }
    }
    return 0;
}
