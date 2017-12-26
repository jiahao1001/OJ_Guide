#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<queue>
using namespace std;
char g[12][12][12];// z y  x
char cmd[20];
int n;
int dist[12][12][12];
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
struct V3{
    pair<int,pair<int,int> > p;
    int& x(){
        return p.first;
    }
    int &y(){
        return p.second.first;
    }
    int &z(){
        return p.second.second;
    }
    V3(){}
    V3(int x,int y,int z){
        p = make_pair(x,make_pair(y,z));
    }
};
bool operator<(const V3 &v1,const V3 &v2){
    return v1.p<v2.p;
}
bool operator==(const V3 &v1, const V3 &v2){
    return v1.p==v2.p;
}
V3 st,ed;
int bfs(){
    queue<V3> q;
    q.push(st);
    memset(dist,-1,sizeof dist);
    dist[st.x()][st.y()][st.z()] = 0;
    while(!q.empty()){
        V3 h = q.front();
        q.pop();
        int d = dist[h.x()][h.y()][h.z()];
        if(h==ed) return d;
        int x = h.x(), y = h.y(), z=h.z();
        int nx,ny,nz;
        for(int k=0;k<6;k++){
            nx = x+dx[k], ny = y+dy[k], nz = z+dz[k];
            if(nx<0 || nx>= n || ny<0 || ny>=n
               || nz<0 || nz>=n
               || g[nx][ny][nz]=='X' || dist[nx][ny][nz]!=-1) continue;
            dist[nx][ny][nz] = d+1;
            q.push(V3(nx,ny,nz));
        }
        
    }
    return -1;
}
int main()
{
    while(scanf("%s",cmd)!=EOF){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%s",g[i][j]);
        scanf("%d%d%d",&st.z(),&st.y(),&st.x());
        scanf("%d%d%d",&ed.z(),&ed.y(),&ed.x());
        int r = bfs();
        if(r==-1)printf("NO ROUTE\n");
        else printf("%d %d\n",n,r);
        scanf("%s",cmd);
    }
    return 0;
}
