
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int xs[10010],ys[10010];
int l[1000],r[1000];
int f[1000],rk[1000];
int N,P;
int FD(int x){
    if(x==f[x]) return x;
    int r = FD(f[x]);
    f[x] = r;
    return r;
}
void UN(int x,int y){ //x<y
    x=FD(x),y=FD(y);
    if(x==y)return;
    if(rk[x]<rk[y]) f[x]=y, l[y] = l[x];
    else{
        f[y]=x, r[x] = r[y];
        if(rk[x]==rk[y]) rk[x]++;
    }
}
int color(int k){
    int conn = 0;
    for(int i=0;i<N;i++) f[i] = i,l[i]=r[i]=i,rk[i]=0;
    for(int i=0;i<P;i++){
        int x,y;
        x = (xs[i]+k)%N;
        y = (ys[i]+k)%N;
        if(x>y) swap(x,y);
        int rx = FD(x), ry = FD(y);
        if(rx==ry) continue;
        y = r[rx]+1;
        while(y<=l[ry]){
            conn++;
            UN(rx,y);
            rx = FD(rx);
            y = r[rx]+1;
        }
    }
    return conn;
    
}
int main(){
    scanf("%d%d",&N,&P);
    for(int i=0;i<P;i++){
        scanf("%d%d",xs+i,ys+i);
        xs[i]--,ys[i]--;
    }
    int ans = 1000;
    for(int k=0;k<N;k++){
        // x = (x+k)%N
        ans = min(ans,color(k));
    }
    printf("%d\n",ans);
    return 0;
}
