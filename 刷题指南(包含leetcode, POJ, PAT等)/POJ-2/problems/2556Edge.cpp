#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<set>
#include<string.h>
#include<queue>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    string cmd;
    while(cin>>cmd){
        int dir = 1;
        int x = 310,y=420;
        printf("300 420 moveto\n310 420 lineto\n");
        for(int i=0;i<cmd.size();i++){
            if(cmd[i]=='A') dir = (dir+1)%4;
            else dir = (dir+3)%4;
            x += dx[dir]*10, y+=dy[dir]*10;
            printf("%d %d lineto\n",x,y);
        }
        printf("stroke\nshowpage\n");
    }
    return 0;
}
