#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
int T,N,n,m;
struct Pupil
{
    int h;
    string sex;
    string music;
    string sport;
} pupils[500];
int g[500][500];
int mtoV[500],ntoV[500];
int love(int i,int j)
{
    i=ntoV[i],j=mtoV[j];
    return abs(pupils[i].h-pupils[j].h)<=40 && pupils[i].music==pupils[j].music && pupils[i].sport!=pupils[j].sport;
    
}
int link[500];
int vis[500];
int dfs(int u)
{
    for(int i=0;i<m;i++)
        if(g[u][i]&&!vis[i]){
            vis[i]=1;
            if(link[i]==-1||dfs(link[i]))
            {
                link[i]=u;
                return 1;
            }
            //vis[i]=0;
        }
    return 0;
}
int match()
{
    memset(link,-1,sizeof(link));
    int mat=0;
    for(int i=0;i<n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) mat++;
    }
    return mat;
}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N;
        n=m=0;
        for(int i=0;i<N;i++)
        {
            cin>>pupils[i].h>>pupils[i].sex>>pupils[i].music>>pupils[i].sport;
            if(pupils[i].sex=="M") ntoV[n++]=i;
            else mtoV[m++]=i;
        }
        //cout<<"good"<<endl;
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(love(i,j)) g[i][j]=1;
            }
        cout<<N-match()<<endl;
    }
    return 0;
}
