#include<iostream>
#include<stdio.h>
#include<algorithm>
#define N 1000
#define M 20000
using namespace std;
int n,m,a,b,c;
struct E{
    int a,b,c;
}elist[M];
bool operator<(const E& e1,const E& e2)
{
    return e1.c<e2.c;
}
int p[N],rank1[N];
inline void make_set(int i)
{
    p[i]=i;
}
inline int find_set(int i)
{
    if(p[i]!=i) p[i]=find_set(p[i]);
    return p[i];
}
inline void union_set(int x,int y)
{
    x=find_set(x),y=find_set(y);
    if(rank1[x]<rank1[y]) p[x]=y;
    else{
        p[y]=x;
        if(rank1[x]==rank1[y]) rank1[x]++;
    }
    
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        elist[i].a=a-1,elist[i].b=b-1;
        elist[i].c=c;
    }
    sort(elist,elist+m);
    for(int i=0;i<n;i++)
        make_set(i);
    int cnt=0;
    int total=0;
    for(int i=m-1;i>=0;i--)
    {
        a=find_set(elist[i].a);
        b=find_set(elist[i].b);
        if(a!=b){
            union_set(a,b);
            total+=elist[i].c;
            cnt++;
        }
    }
    if(cnt!=n-1) printf("-1\n");
    else printf("%d\n",total);
    
}
