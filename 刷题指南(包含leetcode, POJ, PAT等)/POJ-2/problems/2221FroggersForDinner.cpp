#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
int road[10][10];
char cmd[20];
int frog[10];
int tmp[10];
int main()
{
    while(scanf("%s",cmd)!=EOF){
        for(int i=1;i<=8;i++)
            for(int j=0;j<=9;j++)
                scanf("%d",&road[i][j]);
        for(int i=0;i<10;i++)
            frog[i] = 1;
        scanf("%s",cmd);
        for(int t=1;t<=8;t++){
            for(int i=1;i<=8;i++){
                bool kill = (i==t);
                for(int j=0;j<10;j++)
                    if(road[i][j]&&kill) frog[j] = 0;
                for(int j=0;j<10;j++)
                        tmp[j] = road[i][j],road[i][j] = 0;
                    for(int j=0;j<10;j++)
                        if(tmp[j]){
                            int d = tmp[j];
                            int jj = j;
                            for(int k=1;k<=d;k++){
                                if(i<=4) jj--;
                                else jj++;
                                if(jj==10) jj-=10;
                                if(jj==-1) jj+=10;
                                if(kill)frog[jj] = 0;
                            }
                            road[i][jj] = d;
                        }
            }
        }
        bool killed = true;
        for(int i=0;i<10;i++)
            if(frog[i]) killed = false;
        if(killed)printf("FROGGER\n");
        else printf("LEFTOVER POSSUM\n");
    }
    return 0;
}
