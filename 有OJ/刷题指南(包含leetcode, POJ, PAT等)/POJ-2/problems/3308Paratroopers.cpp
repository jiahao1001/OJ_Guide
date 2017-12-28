#include <vector>
#include <limits.h>
#include <iostream>
#include <float.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef double flow_t;
int tt, n, m, l, a, b;
#define N 120
#define E 600<<2
#define eps 1e-8
struct edge{
    int x,y,nxt;
    flow_t c;
} elist[E];
const flow_t inf = DBL_MAX;
//init  ne=0, head[] -1
int ne,head[N],cur[N],ps[N],dep[N];
void addedge(int x,int y,flow_t c)
{
    elist[ne].x = x, elist[ne].y = y, elist[ne].c = c;
    elist[ne].nxt = head[x], head[x] = ne++;
    elist[ne].x = y, elist[ne].y = x, elist[ne].c = 0; // 0 if edge is directed
    elist[ne].nxt = head[y], head[y] = ne++;
}

flow_t flow(int n,int s,int t)
{
    flow_t tr;
    flow_t res = 0;
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
                if(elist[j].c>eps && -1 == dep[k=elist[j].y])
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
                if(elist[j].c>eps && dep[i]+1 == dep[elist[j].y]) break;
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
    scanf("%d", &tt);
    while(tt--)
    {
        ne = 0;
        memset(head,-1,sizeof head);
        scanf("%d%d%d", &n, &m, &l);
        int s = 0, t = n + m + 1;
        //dinic.init(t+1,s,t);
        double tmp;
        for(int i = 1; i <= n && scanf("%lf", &tmp); i++) addedge(s, i, log(tmp));
        for(int j = 1; j <= m && scanf("%lf", &tmp); j++) addedge(j + n, t, log(tmp));
        while(l-- && scanf("%d%d", &a, &b)) addedge(a, b + n, inf);
        tmp = flow(t+1,s,t);
        printf("%.4f\n", exp(tmp));
    }
    return 0;
}
