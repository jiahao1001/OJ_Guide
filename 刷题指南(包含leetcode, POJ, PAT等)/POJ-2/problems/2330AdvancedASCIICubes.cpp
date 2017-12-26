#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


// 6*7 
char cube[][10]=
{
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+..",
};
int A[50][50];
char art[400][310];
int w,h;
inline void draw_cube(int i,int j,int k){
    //draw a cube level h
    //start from x,y;
    int x,y;
    x= i*2, y = j*4+i*2;
    x+=(k-1)*3;
    for(int i=x;i<x+6;i++)
        for(int j=y;j<y+7;j++){
            char c = cube[5-i+x][j-y];
            if(c=='.') continue;
            else art[i][j] = c;
        }
}
void print(){
    for(int i=h-1;i>=0;i--)
        printf("%s\n",art[i]);
}
int main()
{
    int n,m;
    int kn=0;
    h = 0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&A[i][j]),h=max(h,6+(A[i][j]-1)*3+2*(n-1-i)),kn=max(kn,A[i][j]);
    w = m*4+1 + 2*n;
    memset(art,'.',sizeof art);
    for(int i=0;i<h;i++) art[i][w] = '\0';
    
    
    //from bottom to up
    //for far to near
    for(int k=1;k<=kn;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(A[i][j]){
                    A[i][j]--;
                    draw_cube(n-1-i,j,k);
                    //print();
                    //printf("\n");
                }
            }
    print();
    return 0;
}
