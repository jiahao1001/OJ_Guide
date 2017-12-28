#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
const int inf = INT_MAX/2;

int n,c,e,bound;
long long square[100],base[6][6];
bool ok;
inline long long get(int x){
    return 1ll<<(x-1);
}
inline int geth(int i,int j){
    return (2*n+1)*(i-1)+j;
}
inline int getv(int i,int j){
    return (2*n+1)*(i-1)+j+n;
}

void build(){
    c = 0;
    memset(base,0,sizeof base);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            base[i][j] |= get(geth(i,j)) | get(geth(i+1,j));
            base[i][j] |= get(getv(i,j)) | get(getv(i,j+1));
            square[c++] = base[i][j];
        }
    for(int size = 2;size<=n;size++)
        for(int i=1;i+size-1<=n;i++)
            for(int j=1;j+size-1<=n;j++){
                square[c] = 0;
                for(int a=0;a<size;a++){
                    for(int b=0;b<size;b++)
                        square[c] ^= base[i+a][j+b];
                }
                c++;
            }
}
int dfs(long long state, int depth) {
    int h = 0;
    long long u = 0, s = state;
    for (int i = 0; i < c; i++) {
        if ((s & square[i]) == square[i]) {
            h += 1;
            s ^= square[i];
            if (u == 0)
                u = square[i];
        }
    }
    if (h == 0) {
        ok = true;
        return depth;
    }
    if (depth + h > bound) {
        return depth + h;
    }
    
    int newbound = inf;
    for (int i = 1; i <= e; i++) {
        if (u & get(i)) {
            int b = dfs(state ^ get(i), depth + 1);
            if (ok)
                return b;
            newbound = min(b, newbound);
        }
    }
    return newbound;
}



int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        build();
        e = 2*n*(n+1);
        int k,x;
        long long state = (1ll<<e) - 1;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d",&x);
            state ^= 1ll<<(x-1);
        }
        ok = false;
        bound = 0;
        while(!ok) bound = dfs(state,0);
        printf("%d\n",bound);
    }
    return 0;
}
