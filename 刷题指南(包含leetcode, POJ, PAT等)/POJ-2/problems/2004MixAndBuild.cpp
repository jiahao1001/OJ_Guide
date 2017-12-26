#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;
struct Word{
    int w;
    unsigned int h[20],hs;
    int dp,p;
};
vector<Word> level[21];
char word[20000][21];
int n;
int len[10000];
void dfs(int i,int j){
    
    int p = level[i][j].p;
    if(p!=-1) dfs(i-1,p);
    printf("%s\n",word[level[i][j].w]);
}
int main(){
    int x,y;
    int best = 1;
    n = 0;
    while(scanf("%s",word[n++])!=EOF){
        len[n-1] = strlen(word[n-1]);
    }
    n--;
    for(int i=0;i<n;i++) strcpy(word[n+i],word[i]),sort(word[n+i],word[n+i]+len[i]);
    for(int i=0;i<n;i++){
        level[len[i]].push_back(Word());
        Word &wd = level[len[i]].back();
        wd.w = i;
        wd.dp = 1,wd.p = -1;
        wd.hs = 0;
        for(int j=0;j<len[i];j++){
            wd.h[j] = 0;
            wd.hs = wd.hs*26+(word[i+n][j]-'a');
            for(int k=0;k<len[i];k++)
                if(k!=j) wd.h[j] = wd.h[j]*26 + (word[i+n][k]-'a');
        }
    }
    y=0;
    for(x=1;x<=20;x++)
        if(level[x].size()) break;
    for(int i=x;i<20;i++){
        for(int j=0;j<level[i+1].size();j++){
            Word &wd = level[i+1][j];
            for(int k=0;k<level[i].size();k++){
                int cnt;
                for(cnt=0;cnt<len[wd.w];cnt++)
                    if(wd.h[cnt]==level[i][k].hs) break;
                if(cnt<len[wd.w]){
                    if(level[i][k].dp+1>wd.dp) wd.dp = level[i][k].dp+1, wd.p = k;
                    if(wd.dp>best) best = wd.dp,x = i+1,y = j;
                }
            }
        }
    }
    dfs(x,y);
}
