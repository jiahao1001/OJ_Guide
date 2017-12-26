#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
#include<sstream>
using namespace std;
char board[8][8];
int main()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++){
            if(abs(i-j)%2) board[i][j]=':';
            else board[i][j]='.';
        }
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    istringstream ss1(s1);
    istringstream ss2(s2);
    string s,token;
    ss1>>s;
    int i,j;
    while(getline(ss1,token,',')){
        if(token[0]==' ') token = token.substr(1);
        if(token.size()==3){
            i=7-(token[2]-'1');
            j = token[1]-'a';
            board[i][j] = token[0];
        }else{
            i = 7-(token[1]-'1');
            j = token[0]-'a';
            board[i][j] = 'P';
        }
    }
    
    ss2>>s;
    
    while(getline(ss2,token,',')){
        if(token[0]==' ') token = token.substr(1);
        if(token.size()==3){
            i=7-(token[2]-'1');
            j = token[1]-'a';
            board[i][j] = tolower(token[0]);
        }else{
            i = 7-(token[1]-'1');
            j = token[0]-'a';
            board[i][j]= 'p';
        }
    }
    
    
    
    
    printf("+---+---+---+---+---+---+---+---+\n");
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(abs(i-j)%2) printf("|:");
            else printf("|.");
            putchar(board[i][j]);
            if(abs(i-j)%2) printf(":");
            else printf(".");
        }
        printf("|\n");
        printf("+---+---+---+---+---+---+---+---+\n");
    }
    

    return 0;
}
