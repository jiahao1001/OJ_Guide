
#include <iostream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <queue>
using namespace std;
const int N = 110;
struct Act{
    char op;
    int x,y;
    Act(char _op,int _x,int _y):op(_op),x(_x),y(_y){};
    void print(){
        if(op=='F') printf("FILL(%d)\n",x);
        else if(op=='D') printf("DROP(%d)\n",x);
        else printf("POUR(%d,%d)\n",x,y);
    }
    Act(){}
};

Act acts[110][110];
pair<int,int> prev1[N][N];
int dist[N][N];
queue<pair<int,int> > Q;
void print(int x,int y){
    
    if(x+y==0) return;
    print(prev1[x][y].first,prev1[x][y].second);
    acts[x][y].print();
}
int main(){
    int A,B,C;
    int x,y;
    int xx,yy;
    scanf("%d%d%d",&A,&B,&C);
    memset(dist,-1,sizeof(dist));
    dist[0][0] = 0;
    Q.push(make_pair(0,0));
    while(!Q.empty()){
        pair<int,int> head = Q.front();
        Q.pop();
        x = head.first;
        y = head.second;
        if(head.first==C || head.second==C){
            printf("%d\n",dist[x][y]);
            print(x,y);
            return 0;
        }
        //fill
        xx=A,yy=y;
        if(dist[xx][yy]<0){
            dist[xx][yy] = dist[x][y]+1;
            prev1[xx][yy] = make_pair(x,y);
            acts[xx][yy] = Act('F',1,-1);
            Q.push(make_pair(xx, yy));
        }
        xx=x,yy=B;
        if(dist[xx][yy]<0){
            dist[xx][yy] = dist[x][y]+1;
            prev1[xx][yy] = make_pair(x,y);
            acts[xx][yy] = Act('F',2,-1);
            Q.push(make_pair(xx, yy));
        }
        //drop
        xx=0,yy=y;
        if(dist[xx][yy]<0){
            dist[xx][yy] = dist[x][y]+1;
            prev1[xx][yy] = make_pair(x,y);
            acts[xx][yy] = Act('D',1,-1);
            Q.push(make_pair(xx, yy));
        }
        xx=x,yy=0;
        if(dist[xx][yy]<0){
            dist[xx][yy] = dist[x][y]+1;
            prev1[xx][yy] = make_pair(x,y);
            acts[xx][yy] = Act('D',2,-1);
            Q.push(make_pair(xx, yy));
        }

        //pour
        int e = A-x;
        xx = x+min(e,y);
        yy = y-min(e,y);
        if(dist[xx][yy]<0){
            dist[xx][yy] = dist[x][y]+1;
            prev1[xx][yy] = make_pair(x,y);
            acts[xx][yy] = Act('P',2,1);
            Q.push(make_pair(xx, yy));
        }
        
        e = B-y;
        xx = x-min(e,x);
        yy = y+min(e,x);
        if(dist[xx][yy]<0){
            dist[xx][yy] = dist[x][y]+1;
            prev1[xx][yy] = make_pair(x,y);
            acts[xx][yy] = Act('P',1,2);
            Q.push(make_pair(xx, yy));
        }
        
    }
    printf("impossible\n");
    return 0;
}
