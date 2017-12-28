#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string.h>
#include<stack>
#include<stdlib.h>
#include<set>
#include<string>
#include<limits.h>
#include<map>
#include<algorithm>
#include <queue>
using namespace std;
int n,m,L,K;
struct Snake{
    int loc[8];
    int f;
    string hash;
};
bool operator<(const Snake &s1, const Snake &s2){
    return s1.f>s2.f;
}
inline string hash(const Snake& s){
    string h ="";
    char str[10];
    for(int i=0;i<L;i++){
        sprintf(str,"%d",s.loc[i]);
        h+=string(str)+"|";
    }
    return h;
}

Snake init;
int board[20][20];
int visited[20][20];
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
map<string,int> dist;
inline int h(int p){ //heuristic cost
    return visited[p/m][p%m];
}
inline int A_star(){
    dist.clear();
    priority_queue<Snake> pq;
    dist[hash(init)] = 0;
    
    pq.push(init);
    int x,y,nx,ny;
    
    while(!pq.empty()){
        //cout<<"hi"<<endl;
        Snake first = pq.top();
        //cout<<hash(first)<<endl;
        pq.pop();
        int d = dist[first.hash];
        int head = first.loc[0];
        if(head==0) return d;
        x = head/m, y = head%m;
        for(int k=0;k<4;k++){
            nx = x+dx[k], ny = y+dy[k];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(board[nx][ny]) continue; //occupied by block
            bool body = false;
            for(int i=1;i<L;i++){
                if(first.loc[i]==nx*m+ny) {
                    body = true;
                    break;
                }
            }
            if(body) continue;
            //cout<<"has next"<<endl;
            Snake next = first;
            for(int i=L-1;i>=1;i--) next.loc[i]=next.loc[i-1];
            next.loc[0] = nx*m+ny;
            next.f = d+1+h(next.loc[0]);
            next.hash = hash(next);
            if(dist.count(next.hash)) continue;
            dist[next.hash] = d+1;
            //cout<<hash(next)<<endl;
            pq.push(next);
        }
        
    }
    
    return -1;
}
void bfs(){
    visited[0][0] = 0;
    queue<int> Q;
    Q.push(0);
    int x,y, nx,ny;
    while(!Q.empty()){
        int head = Q.front();
        Q.pop();
        x = head/m, y = head%m;
        for(int k=0;k<4;k++){
            nx = x+dx[k], ny = y+dy[k];
            if(nx<0 || nx>=n || ny<0 || ny>=m ) continue;
            if(board[nx][ny] || visited[nx][ny]!=-1) continue;
            visited[nx][ny] = visited[x][y]+1;
            Q.push(nx*m+ny);
        }
    }
}
int main(){
    int x,y;
    int q=1;
    while(scanf("%d%d%d",&n,&m,&L),n||m||L){
        for(int i=0;i<L;i++){
            scanf("%d%d",&x,&y);
            x--,y--;
            init.loc[i] = x*m+y;
        }
        
        init.hash = hash(init);
        memset(board,0,sizeof(board));
        scanf("%d",&K);
        for(int i=0;i<K;i++){
            scanf("%d%d",&x,&y);
            x--,y--;
            board[x][y] = 1;
        }
        memset(visited,-1,sizeof(visited));
        bfs();
        init.f = 0+h(init.loc[0]);
        if(visited[init.loc[0]/m][init.loc[0]%m]==-1){
            printf("Case %d: %d\n",q++,-1);
            continue;
        }
        
        printf("Case %d: %d\n",q++,A_star());
    }
    return 0;
}
