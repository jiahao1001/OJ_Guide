#include<iostream>
#include<stdio.h>
#include<set>
#define MAXN 10001
using namespace std;
int A[MAXN];
int N,I,H,R;
int a,b;
set<int> see;
inline int lowbit(int x)
{
    return x&(-x);
}
void add(int v,int x)
{
    while(v) A[v]+=x,v-=lowbit(v);
}
int sum(int x)
{
    int t=0;
    while(x<=N) t+=A[x],x+=lowbit(x);
    return t;
}
int main()
{
    cin>>N>>I>>H>>R;
    for(int i=0;i<R;i++)
    {
        cin>>a>>b;
        if(a>b) swap(a,b);
        if(see.find(a*(N+1)+b)!=see.end()) continue;
        see.insert(a*(N+1)+b);
        a++,b--;
        add(b,1);
        add(a-1,-1);
    }
    for(int i=1;i<=N;i++)
        cout<<H-sum(i)<<endl;
    return 0;
}
