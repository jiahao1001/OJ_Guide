#include<iostream>
#include<stdio.h>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
const int N = 100;
int n;
char grid[N][N+10];
inline int place(int i,int j){
    if(i<0||i>=n||j<0||j>=n) return 2;
    if(grid[i][j]=='B') return 2;
    if(grid[i][j]=='*') return 1;
    return 0;
}
PII cows[10000];
int cnt;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",grid[i]);
    cnt = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j]=='J') cows[cnt++]=make_pair(i,j);
    int best = 0;
    for(int i=0;i<cnt;i++)
        for(int j=cnt-1;j>=0;j--)
        {
            if(i==j) continue;
            int dx = cows[i].first-cows[j].first;
            int dy = cows[i].second-cows[j].second;
            if(dx*dx+dy*dy<best) continue;
            int x,y;
            int need = 0;
            x=cows[i].first-dy,y=cows[i].second+dx;
            if(x<0 || x>=n || y<0 || y>=n) continue;
            if(grid[x][y]=='B') continue;
            if(grid[x][y]=='*') need++;
            
            x=cows[j].first-dy,y=cows[j].second+dx;
            if(x<0 || x>=n || y<0 || y>=n) continue;
            if(grid[x][y]=='B') continue;
            if(grid[x][y]=='*')need++;
            
            
            if(need<=1) best = max(best,dx*dx+dy*dy);
        }
    printf("%d\n",best);
    return 0;
}
