
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char b[33][35];
string cmd;
int main(){
    int t;
    scanf("%d",&t);
    for(int q=1;q<=t;q++){
        printf("Bitmap #%d\n",q);
        memset(b,'.',sizeof(b));
        for(int i=1;i<=32;i++)
            b[i][33]='\0';
        int x,y;
        scanf("%d%d",&x,&y);
        cin>>cmd;
        for(int i=0;i<cmd.size()-1;i++){
            char &c = cmd[i];
            if(c=='N'){
                b[y+1][x+1]='X';
                y++;
            }else if(c=='W'){
                b[y+1][x]='X';
                x--;
            }else if(c=='S'){
                b[y][x] ='X';
                y--;
                
            }else if(c=='E'){
                b[y][x+1] = 'X';
                x++;
            }
        }
        for(int i=32;i>=1;i--)
            printf("%s\n",b[i]+1);
        printf("\n");
    }
    return 0;
}
