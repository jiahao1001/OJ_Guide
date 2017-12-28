#include<iostream>
#include<stdio.h>
#include<queue>
#include<utility>
#include<string.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 22;
const int M = 50;
int lim;
char bd[M][N][M];
int n,m;
int dist[M*N*M];
inline void build_traffic(){
    //build the board config for time 0,1...m-1
    for(int k=1;k<m;k++){
        for(int i=0;i<n;i++){
            if((i+n-2)%2){//left
                for(int j=0;j<m-1;j++)
                    bd[k][i][j] = bd[k-1][i][j+1];
                bd[k][i][m-1] = bd[k-1][i][0];
            }else{
                bd[k][i][0] = bd[k-1][i][m-1];
                for(int j=1;j<m;j++)
                    bd[k][i][j] = bd[k-1][i][j-1];
            }
        }
    }
}
PII frog,goal;
inline int conf(int k,int i,int j){
    return k*n*m+i*m+j;
}
inline void decode(int h,int &k,int &i,int &j){
    j = h%m;
    h/=m;
    i = h%n;
    h/= n;
    k = h;
}
int bfs(){
    memset(dist,-1,sizeof dist);
    //printf("frog (%d,%d) goal (%d,%d)\n",frog.first,frog.second,goal.first,goal.second);
    
    int s = conf(0,frog.first,frog.second);
    dist[s] = 0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int h = Q.front();
        Q.pop();
        int k,i,j;
        int x,y;
        decode(h,k,i,j);
        if(i==goal.first && j==goal.second) return dist[h];
        if(dist[h]>=lim) continue; //no need to expand
        k=(k+1)%m;
        for(int dx=-1;dx<=1;dx++)
            for(int dy=-1;dy<=1;dy++)
                if(!dx || !dy){
                    x = i+dx, y = j+dy;
                    if(x<0 || x>=n || y<0 || y>=m) continue;
                    if(bd[k][x][y]=='X') continue;
                    int s = conf(k,x,y);
                    if(dist[s]!=-1) continue;
                    dist[s] = dist[h]+1;
                    Q.push(s);
                }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&lim);
        scanf("%d%d",&n,&m);
        n+=2;
        //n-2 is to right
        for(int i=0;i<n;i++)
            scanf("%s",bd[0][i]);
        for(int j=0;j<m;j++)
            if(bd[0][0][j]=='G') goal.first = 0, goal.second = j;
        for(int j=0;j<m;j++)
            if(bd[0][n-1][j]=='F') frog.first = n-1, frog.second = j;
        build_traffic();
        int step = bfs();
        if(step<0) printf("The problem has no solution.\n");
        else printf("The minimum number of turns is %d.\n",step);
    }
    return 0;
}
