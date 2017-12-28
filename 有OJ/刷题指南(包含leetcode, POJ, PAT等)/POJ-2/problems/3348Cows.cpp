#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct Pt{
    int x,y;
};
bool mult(Pt sp, Pt ep, Pt op){
    return (sp.x-op.x)*(ep.y-op.y) >= (ep.x-op.x)*(sp.y-op.y);
}
bool operator<(const Pt &l,const Pt &r)
{
    return l.y<r.y || (l.y==r.y && l.x<r.x);
}
int graham(Pt pnt[],int n, Pt res[]){
    int i,len,k=0,top=1;
    sort(pnt,pnt+n);
    if(n==0) return 0; res[0]=pnt[0];
    if(n==1) return 1; res[1]=pnt[1];
    if(n==2) return 2; res[2]=pnt[2];
    for(i=2;i<n;i++){
        
        while(top && mult(pnt[i],res[top],res[top-1])) top--;
        res[++top]=pnt[i];
    }
    len=top;res[++top]=pnt[n-2];
    for(i=n-3;i>=0;i--){
        while(top!=len && mult(pnt[i],res[top],res[top-1])) top--;
        res[++top] =pnt[i];
    }
    return top;
}
Pt tree[10000];
Pt res[10001];
int n;
int cross(Pt p0,Pt p1,Pt p2)
{
    return (p1.x-p0.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p1.y-p0.y);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&tree[i].x,&tree[i].y);
    int cnt=graham(tree,n,res);
    //for(int i=0;i<cnt;i++)
    //  cout<<res[i].x<<" "<<res[i].y<<endl;
    int area=0;
    for(int i=2;i<cnt;i++)
        area+=cross(res[0],res[i-1],res[i]);
    printf("%d\n",area/100);
    return 0;
}


