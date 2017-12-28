#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define N 100
#define M 10000
using namespace std;
int n,m,a,b,c;
struct E{
    int a,b,c;
}elist[M];
int in_MST[M];
bool operator<(const E& e1,const E& e2)
{
    return e1.c<e2.c;
}
int p[N],rank1[N];
int g[N][N];
int in_tree[N][N];
int bot[N][N];
inline void make_set(int i)
{
    p[i]=i;
    rank1[i]=0;
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
int vis[N];
void dfs(int u,int f,int i,int mm)
{
    vis[u]=1;
    bot[i][u]=mm;
    for(int j=0;j<n;j++)
        if(!vis[j] && in_tree[u][j] && j!=f) dfs(j,u,i,max(mm,g[u][j]));
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(g,0x3f,sizeof(g));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            a--,b--;
            elist[i].a=a,elist[i].b=b;
            elist[i].c=c;
            g[a][b]=c;
            g[b][a]=c;
        }
        memset(in_MST,0,sizeof(in_MST));
        memset(in_tree,0,sizeof(in_tree));
        sort(elist,elist+m);
        for(int i=0;i<n;i++)
            make_set(i);
        
        int total=0;
        for(int i=0;i<m;i++)
        {
            a=find_set(elist[i].a);
            b=find_set(elist[i].b);
            if(a!=b){
                union_set(a,b);
                total+=elist[i].c;
                in_MST[i]=1;
                in_tree[elist[i].a][elist[i].b]=1;
                in_tree[elist[i].b][elist[i].a]=1;
            }
        }
        for(int i=0;i<n;i++){
            memset(vis,0,sizeof(vis));
            dfs(i,-1,i,0);
        }
        int smst=0x3f3f3f3f;
        
        for(int i=0;i<m;i++)
            if(!in_MST[i]){
                smst=min(smst,total+elist[i].c-bot[elist[i].a][elist[i].b]);
            }
        if(smst==total) printf("Not Unique!\n");
        else printf("%d\n",total);
    }
    return 0;
}
