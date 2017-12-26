#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 40010
using namespace std;
//x,y is the offset to parent
class UnionFindSet{
public:
    int f[MAXN],rank[MAXN];
    int dx[MAXN],dy[MAXN];
    UnionFindSet(int n){
        for(int i=1;i<=n;i++)
            f[i]=i;
        memset(dx,0,sizeof(dx));
        memset(dy,0,sizeof(dy));
        memset(rank,0,sizeof(rank));
    }
    int find(int u){
        if(f[u]==u) return u;
        int p=find(f[u]);
        dx[u]+=dx[f[u]],dy[u]+=dy[f[u]];
        f[u]=p;
        return p;
    }
    void merge(int u,int v,int x,int y){
        //cout<<"mergin "<<u<<" "<<v<<" "<<x<<" "<<y<<endl;
        if(rank[u]<rank[v]) f[u]=v,dx[u]+=-x,dy[u]+=-y;
        else{
            f[v]=u,dx[v]+=x,dy[v]+=y;
            if(rank[u]==rank[v]) rank[u]++;
        }
    }
};
int N,M,K;
struct Road
{
    int u,v,dx,dy;
    void init(int _u,int _v,int len,char dir){
        u=_u,v=_v;
        dx=dy=0;
        switch(dir){
        case 'E':
            dx=len;
            break;
        case 'W':
            dx=-len;
            break;
        case 'S':
            dy=-len;
            break;
        case 'N':
            dy=len;
            break;
        }
    }
}roads[MAXN];
int u,v,len,dx,dy;
char dir;
struct Query
{
    int u,v,t;
}queries[10000];
int order[10000];
int dist[10000];
bool cmp(int a,int b)
{
    return queries[a].t<queries[b].t;
}
int main()
{
    cin>>N>>M;
    UnionFindSet ufs(N);
    for(int i=1;i<=M;i++)
    {
        cin>>u>>v>>len>>dir;
        roads[i].init(u,v,len,dir);
    }
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>queries[i].u>>queries[i].v>>queries[i].t;
        order[i]=i;
    }
    sort(order,order+K,cmp);
    int cnt=0;
    for(int i=1;i<=M;i++)
    {
        u=roads[i].u,v=roads[i].v;
        dx=roads[i].dx,dy=roads[i].dy;
        int p1=ufs.find(u);
        int p2=ufs.find(v);
        if(p1!=p2) ufs.merge(p1,p2,dx-ufs.dx[v]+ufs.dx[u],dy-ufs.dy[v]+ufs.dy[u]);
        while(cnt<K && i==queries[order[cnt]].t){
            u=queries[order[cnt]].u,v=queries[order[cnt]].v;
            p1=ufs.find(u),p2=ufs.find(v);
            if(p1!=p2) dist[order[cnt]]=-1;
            else dist[order[cnt]]=abs(ufs.dx[u]-ufs.dx[v])+abs(ufs.dy[u]-ufs.dy[v]);
            cnt++;
        }
    }
    for(int i=0;i<K;i++)
        printf("%d\n",dist[i]);
    
    return 0;
    
}
