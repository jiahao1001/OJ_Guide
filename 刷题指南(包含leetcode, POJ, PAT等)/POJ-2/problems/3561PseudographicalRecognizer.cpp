
#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
char bd[10][12];
int n,m,t;
void first(int &i,int &j){
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(bd[i][j]!='.') return;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%s",bd[i]);
        int x,y;
        first(x,y);
        if(x==n && y==m){
            printf("INCORRECT\n");
            continue;
        }
        if(bd[x][y]=='-'){
            for(int j=y;j<m;j++){
                if(bd[x][j]=='-') bd[x][j]='.';
                else break;
            }
        }else if(bd[x][y]=='/'){
            for(int i=x,j=y;i<n && j>=0;i++,j--)
                if(bd[i][j]=='/') bd[i][j]='.';
                else break;
            
        }else if(bd[x][y]=='\\'){
            for(int i=x,j=y;i<n && j<m;i++,j++)
                if(bd[i][j]=='\\') bd[i][j]='.';
                else break;
            
        }else if(bd[x][y]=='|'){
            for(int i=x;i<n;i++){
                if(bd[i][y]=='|') bd[i][y]='.';
                else break;
            }
        }
        first(x,y);
        if(x==n && y==m)printf("CORRECT\n");
        else printf("INCORRECT\n");
    }
    return 0;
}
