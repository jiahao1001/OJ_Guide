
#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
using namespace std;
typedef pair<int,int> PII;
int K;
int A,B,N,M;
int get_dir(char d){
    string dir = "NESW";
    return (int)dir.find_first_of(d);
}
int board[105][105];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
vector<int> robot_x;
vector<int> robot_y;
vector<int> robot_dir;
bool forward(int no,int repeat){
    int x = robot_x[no];
    int y = robot_y[no];
    int dir = robot_dir[no];
    for(int i=1;i<=repeat;i++){
        x += dx[dir] , y+= dy[dir];
        if(x<=0 || x> A || y<=0 || y>B){
            printf("Robot %d crashes into the wall\n",no);
            return false;
        }
        if(board[x][y]){
            printf("Robot %d crashes into robot %d\n",no,board[x][y]);
            return false;
        }
    }
    board[robot_x[no]][robot_y[no]]=0;
    robot_x[no] = x;
    robot_y[no] = y;
    board[x][y] = no;
    return true;
}
int main(){
    scanf("%d",&K);
    while(K--){
        memset(board,0,sizeof(board));
        robot_dir.clear();
        robot_x.clear();
        robot_y.clear();
        robot_x.push_back(1);
        robot_y.push_back(1);
        robot_dir.push_back(0);
        scanf("%d%d",&A,&B);
        scanf("%d%d",&N,&M);
        int x,y;
        char dir;
        for(int i=0;i<N;i++){
            scanf("%d %d %c",&x,&y,&dir);
            robot_x.push_back(x);
            robot_y.push_back(y);
            robot_dir.push_back(get_dir(dir));
            board[x][y] = i+1;
        }
        int no,repeat;
        char act;
        bool crashed = false;
        for(int i=0;i<M;i++){
            scanf("%d %c %d",&no,&act,&repeat);
            if(crashed) continue;
            if(act=='F') {
                if(!forward(no,repeat)) crashed = true;
            }else if(act=='L'){
                repeat %= 4;
                robot_dir[no] = (robot_dir[no]+4-repeat)%4;
            }else{
                repeat%=4;
                robot_dir[no] = (robot_dir[no]+repeat)%4;
            }
        }
        if(!crashed) printf("OK\n");
        
    }
    return 0;
}
