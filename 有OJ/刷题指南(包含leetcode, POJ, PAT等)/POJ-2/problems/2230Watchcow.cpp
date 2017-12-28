#include<iostream>
#include<stdio.h>
using namespace std;
int N,M;
struct E{
    int v,next;
}elist[100000];
int head[10001];
int u,v;
int cnt,top;

void addedge(int u,int v)
{
    elist[cnt].v=v;
    elist[cnt].next=head[u];
    head[u]=cnt++;
}
int walked[100000];
void euler(int u)
{
    for(int i=head[u];i!=-1;i=elist[i].next){
        if(walked[i]) continue;
        walked[i]=1;
        euler(elist[i].v);
    }
    printf("%d\n",u);
}
int main()
{
    scanf("%d%d",&N,&M);
    memset(head,-1,sizeof(head));
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    euler(1);
    return 0;
}
