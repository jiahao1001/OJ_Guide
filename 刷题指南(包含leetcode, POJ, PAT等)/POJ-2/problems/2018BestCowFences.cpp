
#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int y[100010];
int st[100010];
inline bool ccw(int x1,int y1,int x2,int y2){
    return x1*y2-x2*y1>0;
}
int main(){
    int N,F,t;
    scanf("%d%d",&N,&F);
    y[0] = 0;
    for(int i=1;i<=N;i++){
        scanf("%d",&t);
        y[i] = y[i-1]+t;
    }
    int head=0,tail=0;
    st[head++] = 0;//instack first
    double ans = 0;
    for(int i=F;i<=N;i++){
        while(tail+1<head &&ccw(i-st[tail],y[i]-y[st[tail]],i-st[tail+1],y[i]-y[st[tail+1]]))tail++;
        ans = max(ans, 1.0*(y[i]-y[st[tail]]) / (i-st[tail]));
        int x = i-F+1;
        while(tail+1<head && !ccw(st[head-1]-st[head-2],y[st[head-1]]-y[st[head-2]],  x-st[head-2],y[x]-y[st[head-2]] )) head--;
        st[head++] = x;
    }
    printf("%d\n",(int)(1000*ans));
    return 0;
}
