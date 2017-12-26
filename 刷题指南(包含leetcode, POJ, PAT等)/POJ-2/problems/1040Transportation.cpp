#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int B = 8;
int train[B];//passenger at station i
struct Order{
    int s,d,n;
}orders[22];
bool operator<(const Order &o1, const Order &o2){
    if(o1.s==o2.s) return o1.d<o2.d;
    return o1.s<o2.s;
}
int n,b,t;
int best;
void dfs(int cur,int earn){
    if(cur==t){
        best = max(best,earn);
        return;
    }
    //cur accept or reject
    dfs(cur+1,earn);
    //accept
    int s = orders[cur].s, d = orders[cur].d, x = orders[cur].n;
    bool ok = true;
    for(int i=s;i<d;i++)
        if(train[i]+x>n) ok = false;
    if(ok){
        for(int i=s;i<d;i++)
            train[i]+=x;
        dfs(cur+1,earn+x*(d-s));
        for(int i=s;i<d;i++)
            train[i]-=x;
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&b,&t),n||b||t){
        for(int i=0;i<t;i++)
            scanf("%d%d%d",&orders[i].s,&orders[i].d,&orders[i].n);
        sort(orders,orders+t);
        memset(train,0,sizeof(train));
        best = 0;
        dfs(0,0);
        printf("%d\n",best);
    }
    return 0;
}
