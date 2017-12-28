#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
char buf[250][260];
char piece[100][25][30];
vector<int> may[130];
int bd[10][10];
int n,h,w;
char s[30];
int up[100],left1[100],down[100],right1[100];
bool done;
void dfs(int i,int j){
    if(i==n){
        for(int k=0;k<n;k++)
            if(down[bd[n-1][k]]) return;
        done = true;
        return;
    }
    if(j==n){
        if(right1[bd[i][j-1]]) return;
        if(!done)dfs(i+1,0);
        return;
    }
    int l = j?(-right1[bd[i][j-1]]+5):5;
    int u = i?(-down[bd[i-1][j]]+5):5;
    int e = u*11+l;
    
    for(int k=0;k<may[e].size();k++){
        if(!done){
            bd[i][j] = may[e][k];
            dfs(i,j+1);
            //cout<<"try "<<e<<" "<<may[e][k]<<endl;
        }
    }
}


int main()
{
    scanf("%d%d%d",&n,&h,&w);
    gets(s);
    int cnt = 0;
    for(cnt=0;cnt<n*n;cnt++){
        for(int i=0;i<h;i++)
            gets(piece[cnt][i]);
        scanf("%d%d%d%d",up+cnt,left1+cnt,down+cnt,right1+cnt);
        int e=(up[cnt]+5)*11+left1[cnt]+5;
        may[e].push_back(cnt);
        gets(s);
        gets(s);
    }
    done = false;
    dfs(0,0);
    
    // 1 0
    // 3 2
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",bd[i][j]);
        printf("\n");
        }*/
    for(int i=0;i<n*h;i++)
        buf[i][n*w] = '\0';

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int pp = bd[i][j];
            for(int x=0;x<h;x++)
                for(int y=0;y<w;y++)
                    buf[i*h+x][j*w+y] = piece[pp][x][y];
        }
    
    for(int i=0;i<n*h;i++)
        printf("%s\n",buf[i]);
    
    return 0;
}
