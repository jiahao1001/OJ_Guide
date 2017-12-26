#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>

using namespace std;
int g[26][26];
int vis[26];
void dfs(int u){
    vis[u] = 1;
    for(int v=0;v<26;v++)
        if(g[u][v]&&!vis[v]) dfs(v);
}
int main()
{
    int T;
    char word[1010];
    scanf("%d",&T);
    while(T--){
        int in[26]={0};
        int out[26]={0};
        
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",word);
            int u = word[0]-'a';
            int v = word[strlen(word)-1]-'a';
            out[u]++;
            in[v]++;
            g[u][v] = 1;
            g[v][u] = 1;
        }
        for(int i=0;i<26;i++){
            if(in[i]||out[i]){
                dfs(i);
                break;
            }
        }
        int flag = true;
        for(int i=0;i<26;i++)
            if((in[i]||out[i])&&!vis[i]){
                flag = false;
                printf("The door cannot be opened.\n");
                break;
            }
        if(!flag) continue;
        int iin=0, oout = 0;
        
        for(int i=0;i<26;i++){
            if(in[i]==out[i])continue;
            if(in[i]==out[i]+1) iin++;
            else if(out[i]==in[i]+1) oout++;
            else {
                flag = false;
                printf("The door cannot be opened.\n");
                break;
            }
        }
        if(flag){
            if(iin==1 && oout==1 || iin+oout==0) printf("Ordering is possible.\n");
            else printf("The door cannot be opened.\n");
        }
        
        
    }
    return 0;
}
