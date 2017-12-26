#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
#define N 10000
using namespace std;
map<int,int> pt_id;


int n,k;
struct Pt
{
    int x,y;
} bananas[16010];
int f[16010],cnt[16010],rank1[16010];
static int dx[4]={0,0,1,-1};
static int dy[4]={1,-1,0,0};
int fu_find(int x)
{
    if(f[x]==x) return x;
    int p=fu_find(f[x]);
    f[x]=p;
    return p;
}
inline void fu_union(int p1,int p2)
{
    if(rank1[p1]<rank1[p2]) f[p1]=p2,cnt[p2]+=cnt[p1];
    else{
        f[p2]=p1,cnt[p1]+=cnt[p2];
        if(rank1[p1]==rank1[p2]) rank1[p1]++;
    }
}
int main()
{
    int x,y;
    int nx,ny;
    int p1,p2;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        x--,y--;
        bananas[i].x=x,bananas[i].y=y;
        pt_id[x*N+y]=i;
    }
    for(int i=1;i<=n;i++)
        f[i]=i,cnt[i]=1;
    //cout<<"good"<<endl;
    for(int i=1;i<=n;i++){
        x=bananas[i].x,y=bananas[i].y;
        int id=pt_id[x*N+y];
        //cout<<"id "<<id<<endl;
        int nid;
        for(int k=0;k<4;k++){
            nx=x+dx[k],ny=y+dy[k];
            if(nx<0 || nx>=10000 || ny<0 ||ny>=10000) continue;
            if(pt_id.find(nx*N+ny)==pt_id.end()) continue;
            nid=pt_id[nx*N+ny];
            if(nid) //neighbor has a tree
            {
                p1=fu_find(id);
                p2=fu_find(nid);
                if(p1!=p2) fu_union(p1,p2);;
            }
        }
        
    }
    //cout<<"what"<<endl;
    
    for(int i=1;i<=n;i++)
        if(f[i]!=i) cnt[i]=0;
    sort(cnt+1,cnt+n+1);
    int answer = 0;
    for(int i=n;i>=1 && i>n-k;i--)
        answer += cnt[i];
    printf("%d\n",answer);
    return 0;
}
