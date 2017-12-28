#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<utility>
using namespace std;
char bd[3][5];
char s[10];
char win;
bool same(char &a,char &b,char &c){
    if(a=='.') return false;
    if (a==b && a==c){
        win = a;
        a=b=c='.';
        return true;
    }
    return false;
}
bool check(){
    for(int i=0;i<3;i++){
        if(same(bd[i][0],bd[i][1],bd[i][2])) return true;
        if(same(bd[0][i],bd[1][i],bd[2][i])) return true;
    }
    if(same(bd[0][0],bd[1][1],bd[2][2])) return true;
    if(same(bd[0][2],bd[1][1],bd[2][0])) return true;
    return false;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x=0,o=0;
        for(int i=0;i<3;i++)
            scanf("%s",bd[i]);
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(bd[i][j]=='X') x++;
                else if(bd[i][j]=='O') o++;
        if(x-o!=0 && x-o!=1){
            printf("no\n");
            continue;
        }
        if(!check()) {
            printf("yes\n");
        }
        else {
            if((win=='X' && o>=x) || (win=='O' && x>o)){
                printf("no\n");
                continue;
            }
            if(check())printf("no\n");
            else printf("yes\n");
        }
    }
    return 0;
}
