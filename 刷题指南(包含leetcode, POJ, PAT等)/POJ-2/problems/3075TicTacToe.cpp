#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<utility>
using namespace std;
char bd[3][3];
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
    while(scanf("%s",s),strcmp(s,"end")){
        int x=0,o=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                bd[i][j] = s[i*3+j];
        for(int i=0;i<9;i++)
            if(s[i]=='X') x++;
            else if(s[i]=='O') o++;
        if(x-o!=0 && x-o!=1){
            printf("invalid\n");
            continue;
        }
        if(!check()) {
            if(o+x==9) printf("valid\n");
            else printf("invalid\n");
        }
        else {
            if((win=='X' && o>x) || (win=='O' && x>o)){
                printf("invalid\n");
                continue;
            }
            if(check())printf("invalid\n");
            else printf("valid\n");
        }
    }
    return 0;
}/*
   OXO
   XOX
   OXO
 */
