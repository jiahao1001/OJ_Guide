#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 1000
#define M 15000
struct E{
    int a,b,c;
} elist[M];
bool operator<(const E& e1,const E& e2)
{
    return e1.c<e2.c;
}
int in_mst[M];
int n,m;
int p[N],rank1[N];
inline void make_set(int x)
{
    p[x]=x,rank1[x]=0;
}
inline int find_set(int x)
{
    if(p[x]!=x) p[x]=find_set(p[x]);
    return p[x];
}
inline void union_set(int x,int y)
{
    x=find_set(x),y=find_set(y);
    if(x==y) return;
    if(rank1[x]<rank1[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(rank1[x]==rank1[y]) rank1[x]++;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int a,b,c;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        a--,b--;
        elist[i].a=a,elist[i].b=b;
        elist[i].c=c;
    }
    sort(elist,elist+m);
    for(int i=0;i<n;i++)
        make_set(i);
    int best=0;
    for(int i=0;i<m;i++)
    {
        a=find_set(elist[i].a);
        b=find_set(elist[i].b);
        if(a!=b){
            union_set(a,b);
            in_mst[i]=1;
            best=max(best,elist[i].c);
        }
    }
    printf("%d\n",best);
    printf("%d\n",n-1);
    for(int i=0;i<m;i++)
        if(in_mst[i]) printf("%d %d\n",elist[i].a+1,elist[i].b+1);
    return 0;
}
