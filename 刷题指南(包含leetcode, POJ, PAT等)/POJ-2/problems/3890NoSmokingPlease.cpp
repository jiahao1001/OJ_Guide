#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define N 1000010
#define E N<<2


struct edge{
    int x,y,nxt,c;
} elist[E];
const int inf = INT_MAX;
//init  ne=0, head[] -1
int ne,head[N],cur[N],ps[N],dep[N];
void addedge(int x,int y,int c)
{
    elist[ne].x = x, elist[ne].y = y, elist[ne].c = c;
    elist[ne].nxt = head[x], head[x] = ne++;
    elist[ne].x = y, elist[ne].y = x, elist[ne].c = c; // 0 if edge is directed
    elist[ne].nxt = head[y], head[y] = ne++;
}

int flow(int n,int s,int t)
{
    int tr;
    int res = 0;
    int i,j,k,f,r,top;
    while(1)
    {
        memset(dep,-1,n*sizeof(int));
        ps[0]=s, dep[s]=0,f=0,r=1;
        while(f!=r)
        {
            i=ps[f++];
            // bfs to get the level subgraph
            for(j=head[i];j!=-1;j=elist[j].nxt)
                if(elist[j].c && -1 == dep[k=elist[j].y])
                {
                    dep[k] = dep[i]+1, ps[r++]=k;
                    if(k==t){
                        f=r;
                        break;
                    }
                }
        }
        if(-1 == dep[t]) break;
        memcpy(cur,head,n*sizeof(int));
        i=s,top=0;
        while(1)
        {
            if(i==t){
                for(k=0,tr=inf;k<top;k++)
                    if(elist[ps[k]].c<tr) tr=elist[ps[f=k]].c;
                for(k=0;k<top;k++)
                    elist[ps[k]].c -= tr, elist[ps[k]^1].c += tr;
                res += tr, top=f, i=elist[ps[top]].x;
            }
            for(j=cur[i];cur[i]!=-1;j=cur[i]=elist[cur[i]].nxt)
                if(elist[j].c && dep[i]+1 == dep[elist[j].y]) break;
            if(j!=-1) ps[top++]=cur[i],i=elist[j].y;
            else{
                if(0==top) break;
                dep[i]=-1, top--, i=elist[ps[top]].x;
            }
        }
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ne=0;
        memset(head,-1,sizeof(head));
        int r;int c;
        int r0,c0,r1,c1;
        scanf("%d %d",&r,&c);
        scanf("%d %d",&r0,&c0);
        scanf("%d %d",&r1,&c1);
        int s=r0*c+c0;
        int tt=r1*c+c1;
        int cap;
        for(int i=0;i<r;i++)
            for(int j=0;j<c-1;j++)
            {
                scanf("%d",&cap);
                if(cap)addedge(i*c+j,i*c+j+1,(cap+1)*1000);
            }
        for(int i=0;i<r-1;i++)
            for(int j=0;j<c;j++)
            {
                scanf("%d",&cap);
                if(cap)addedge(i*c+j,(i+1)*c+j,(cap+1)*1000);
            }
        
        
        printf("%d\n",flow(r*c,s,tt));
        
    }
    return 0;
}
