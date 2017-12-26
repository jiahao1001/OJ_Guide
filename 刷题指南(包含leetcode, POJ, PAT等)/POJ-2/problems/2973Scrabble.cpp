#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;

int n;
char words[1000][10];
char tile[10];
int tile_cnt[256];
int blank;
int w_cnt[256];
int main()
{
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++)
            scanf("%s",words[i]);
        scanf("%s",tile);
        memset(tile_cnt,0,sizeof tile_cnt);
        blank = 0;
        int len = strlen(tile);
        for(int i=0;i<len;i++)
            if(tile[i]=='_') blank++;
            else tile_cnt[tile[i]]++;
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            memset(w_cnt,0,sizeof w_cnt);
            len = strlen(words[i]);
            for(int j=0;j<len;j++) w_cnt[words[i][j]]++;
            int need = 0;
            for(int j=0;j<256;j++)
                need += max(0,w_cnt[j]-tile_cnt[j]);
            if(need<=blank) cnt++;
            
        }
        printf("%d\n",cnt);
        
    }
    return 0;
}
