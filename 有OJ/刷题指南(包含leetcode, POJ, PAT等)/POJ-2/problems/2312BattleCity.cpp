#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int,int> PII;
const int M = 300;
const int N = 305;
char battle[M][N];
int dist[M][N];
int m,n;
int si,sj;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int turns(){
    priority_queue<PII,vector<PII>, greater<PII> > pq;
    //path, loc
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) 
            if(battle[i][j]=='Y') {
            si=i,sj=j;
            break;
        }
    //cout<<si<<" "<<sj<<endl;
    dist[si][sj]= 0;
    int x,y,nx,ny;
    pq.push(make_pair(0,si*n+sj));
    while(!pq.empty()){
        PII head = pq.top();
        pq.pop();
        x = head.second/n, y = head.second%n;
        if(head.first>dist[x][y]) continue;
        if(battle[x][y]=='T') return dist[x][y];
        for(int k=0;k<4;k++){
            nx = x+dx[k], ny = y+dy[k];
            if(nx<0||nx>=m || ny<0 || ny>=n) continue;
            if(battle[nx][ny]=='S'|| battle[nx][ny]=='R') continue;
            int p = head.first;
            if(battle[nx][ny]=='B') p+=2;
            else p+=1;
            if(dist[nx][ny]==-1 || p<dist[nx][ny]){
                dist[nx][ny] = p;
                //printf("dist(%d,%d)=%d\n",nx,ny,p);
                        
                pq.push(make_pair(p,nx*n+ny));
            }
        }
    }
    return -1;
    
}
int main(){
    while(scanf("%d%d",&m,&n),m||n){
        for(int i=0;i<m;i++)
            scanf("%s",battle[i]);
        memset(dist,-1,sizeof(dist));
        printf("%d\n",turns());
    }
    return 0;
}
