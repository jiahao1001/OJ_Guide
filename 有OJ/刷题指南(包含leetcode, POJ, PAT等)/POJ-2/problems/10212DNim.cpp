#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
vector<pii> p;
int board[100][100]; // W,H
int W,H;
inline ULL sqr(int x){
    return x*x;
}
ULL hash1(){
    ULL h = 0;
    for(int i=0;i<p.size();i++)
        for(int j=i+1;j<p.size();j++){
            h += sqr(p[i].first-p[j].first) + sqr(p[i].second-p[j].second);
        }
    return h;
}
void dfs(int i,int j){
    for(int dx=-1;dx<=1;dx++)
        for(int dy=-1;dy<=1;dy++)
            if((dx==0)^(dy==0)){
                if(i+dx<0 || i+dx>=W || j+dy<0 || j+dy>=H) continue;
                if(board[i+dx][j+dy]){
                    board[i+dx][j+dy] = 0;
                    p.push_back(make_pair(i+dx,j+dy));
                    dfs(i+dx,j+dy);
                }
            }
}
int main()
{
    int t,x,y;
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d%d",&W,&H);
        scanf("%d",&k);
        memset(board,0,sizeof board);
        for(int i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            board[x][y] = 1;
        }
        vector<ULL> a;
        for(int i=0;i<W;i++)
            for(int j=0;j<H;j++)
                if(board[i][j]){
                    board[i][j] = 0;
                    p.clear();
                    p.push_back(make_pair(i,j));
                    dfs(i,j);
                    a.push_back(hash1());
                }
        
        memset(board,0,sizeof board);
        for(int i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            board[x][y] = 1;
        }
        vector<ULL> b;
        for(int i=0;i<W;i++)
            for(int j=0;j<H;j++)
                if(board[i][j]){
                    board[i][j] = 0;
                    p.clear();
                    p.push_back(make_pair(i,j));
                    dfs(i,j);
                    b.push_back(hash1());
                }
        if(a.size()!=b.size()){
            printf("NO\n");
            continue;
        }
        bool ok = true;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<a.size();i++)
            if(a[i]!=b[i]) ok = false;
        if(ok) printf("YES\n");
        else printf("NO\n");
        
        
    }
    return 0;
}
