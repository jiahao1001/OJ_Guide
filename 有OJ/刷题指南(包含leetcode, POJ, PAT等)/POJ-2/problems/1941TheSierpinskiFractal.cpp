#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char shape[1<<10][(1<<11)+1];
void draw(int x,int y,int n){
    if(n==1) return;
    int N = 1<<n;
    //draw the upside down triange, recur one three sub
    //side N
    for(int i=y+N/2+1;i+1<=y+N*3/2;i+=4)
        shape[x+N/2-1][i] = '_', shape[x+N/2-1][i+1] = '_';
    int half = y+N;
    for(int i=x+N-1,c=0;i>=x+N/2;i--,c++){
        shape[i][half-c-1] = '\\';
        shape[i][half+c] = '/';
    }
    draw(x+0,y+(N>>1),n-1);
    draw(x+(N>>1),y+0,n-1);
    draw(x+(N>>1),y+N,n-1);
}
int main()
{
    int n;
    while(scanf("%d",&n),n){
        memset(shape,' ',sizeof shape);
        //outmost
        //   1 2
        // 0 1 2 3
        int N = 1<<n;
        int half = 1<<n;
        for(int i=0;i<(1<<n);i++){
            shape[i][half-i-1]='/';
            shape[i][half+i] = '\\';
            shape[i][1<<(n+1)] = '\0';
        }
        for(int i=1;i+1<N*2;i+=4){
            shape[N-1][i]='_';
            shape[N-1][i+1]='_';
        }
        draw(0,0,n);
        for(int i=0;i<N;i++)
            for(int j=(1<<(n+1))-1;j>=0;j--)
                if(shape[i][j]!=' '){
                    shape[i][j+1]='\0';
                    break;
                }
        
        for(int i=0;i<(1<<n);i++)
            printf("%s\n",shape[i]);
        printf("\n");
    }
    return 0;
}
