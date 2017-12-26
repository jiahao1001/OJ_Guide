#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
#include<stack>
#include<set>
using namespace std;
const int N = 50010;
int n,m;
int A[N];
inline int lowbit(int x) { return x&(-x);}
inline void add(int i,int x){
    while(i<=n){
        A[i] += x;
        i+=lowbit(i);
    }
}
inline int sum(int i){
    int s = 0;
    while(i) s+=A[i], i-=lowbit(i);
    return s;
}
stack<int> S;
inline bool check(int i,int x){
    return sum(x)-sum(x-i) == i;
}
inline bool check2(int len,int x){
    return sum(x+len)-sum(x)==len;
}
set<int> destroyed;
int main()
{
    char cmd;
    int x;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        add(i,1);
    for(int i=1;i<=m;i++){
        scanf(" %c",&cmd);
        if(cmd=='D'){
            scanf("%d",&x);
            //if(destroyed.count(x)) continue;
            S.push(x);
            //destroyed.insert(x);
            add(x,-1);
        }else if(cmd=='R'){
            if(S.empty()) continue;
            x = S.top();
            S.pop();
            add(x,1);
        }else{
            scanf("%d",&x);
            if(sum(x)-sum(x-1)==0)
            {
                printf("0\n");
                continue;
            }
            int l = 0, r = x+1;
            while(l+1<r){
                int mid = (l+r)>>1;
                if(check(mid,x)) l=mid;
                else r = mid;
            }
            int m = l;
            l = 0, r = n-x+1;
            while(l+1<r){
                int mid = (l+r)>>1;
                if(check2(mid,x)) l = mid;
                else r = mid;
            }
            printf("%d\n",l+m);
        }
    }
    return 0;
}
