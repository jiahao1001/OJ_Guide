#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
using namespace std;
char s[10010];
int n;
char key[100];
char M[100][100];
void fill(int len){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i*n+j<len) M[i][j] = toupper(s[i*n+j]);
            else M[i][j] = (i*n+j-len)%26+'A';
            //printf("%c",M[i][j]);
        }
        //printf("\n");
    }
    
}
void shake(){
    char c;
    for(int j=0;j<n;j++){
        if(j%2){//down
            c = M[n-1][j];
            for(int i=n-1;i>=1;i--)
                M[i][j] = M[i-1][j];
            M[0][j] = c;
        }else{//up
            c = M[0][j];
            for(int i=0;i<n-1;i++)
                M[i][j] = M[i+1][j];
            M[n-1][j] = c;
        }
    }
}
void rattle(){
    char c;
    for(int i=0;i<n;i++){
        if(i%2){
            //left
            c = M[i][0];
            for(int j=0;j<n-1;j++)
                M[i][j] = M[i][j+1];
            M[i][n-1] = c;
        }else{
            //right
            c = M[i][n-1];
            for(int j=n-1;j>=1;j--)
                M[i][j] = M[i][j-1];
            M[i][0] = c;
        }
    }
}
void roll(){
    char c;
    for(int k=0;k<n/2;k++){
        if(k%2){
            //ccw
            c=M[k][k];
            for(int j=k;j<n-k-1;j++)
                M[k][j] = M[k][j+1];
            for(int i=k;i<n-k-1;i++)
                M[i][n-k-1] = M[i+1][n-k-1];
            for(int j=n-k-1;j>k;j--)
                M[n-k-1][j] = M[n-k-1][j-1];
            for(int i=n-k-1;i>k;i--)
                M[i][k] = M[i-1][k];
            M[k+1][k] = c;
        }else{
            //cw
            c = M[k][k];
            for(int i=k;i<n-k-1;i++)
                M[i][k] = M[i+1][k];
            for(int j=k;j<n-k-1;j++)
                M[n-k-1][j]=M[n-k-1][j+1];
            for(int i=n-k-1;i>k;i--)
                M[i][n-k-1] = M[i-1][n-k-1];
            for(int j=n-k-1;j>k;j--)
                M[k][j] = M[k][j-1];
            M[k][k+1] = c;
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        if(!n) n= 100;
        gets(key);
        gets(s);
        fill(strlen(s));
        for(char *p=key;*p;p++){
            switch(*p){
            case 'S':
                shake();
                break;
            case 'R':
                rattle();
                break;
            case 'L':
                roll();
                break;
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                printf("%c",M[i][j]);
        printf("\n");
    }
    return 0;
}
