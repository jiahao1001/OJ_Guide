#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<ctype.h>
#include<utility>
using namespace std;
char board[8][9];
char s[100];
void print(char c,char prefix, bool comma){
    for(int i=7;i>=0;i--)
        for(int j=0;j<8;j++){
            if(board[i][j]==c){
                if(comma) putchar(',');
                if(prefix!=' ')putchar(prefix);
                putchar(j+'a');
                putchar(7-i+'1');
            }
        }
}
void print1(char c,char prefix, bool comma){
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++){
            if(board[i][j]==c){
                if(comma) putchar(',');
                if(prefix!=' ')putchar(prefix);
                putchar(j+'a');
                putchar(7-i+'1');
            }
        }
}


int main()
{
    gets(s);
    for(int i=0;i<8;i++){
        gets(s);
        for(int j=0;j<8;j++){
            board[i][j] = s[2+4*j];
        }
        gets(s);
    }
    //white upper case
    //K Q R, B N
    //row small first
    printf("White: ");
    print('K','K',false);
    char *seq = "QRBN";
    for(int i=0;i<4;i++)
        print(seq[i],seq[i],true);
    print('P',' ',true);
    putchar('\n');
    
    printf("Black: ");
    print1('k','K',false);
    for(int i=0;i<4;i++)
        print1(tolower(seq[i]),seq[i],true);
    print1('p',' ',true);
    putchar('\n');
    
    
    return 0;
}
