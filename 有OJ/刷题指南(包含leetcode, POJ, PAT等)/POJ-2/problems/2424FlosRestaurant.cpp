#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int,int> PII;
int table[3];
int get_t(char *s){
    int h,m;
    sscanf(s,"%d:%d",&h,&m);
    return h*60+m;
}
int main()
{
    char s[20];
    while(true){
        for(int i=0;i<3;i++) scanf("%d",table+i);
        if(!table[0]) break;
        priority_queue<int,vector<int>,greater<int> > avail[3]; //available table time
        queue<PII> diner[3];
        int tot = 0;
        int cnt;
        while(scanf("%s",s),s[0]!='#'){
            scanf("%d",&cnt);
            diner[(cnt-1)/2].push(make_pair(get_t(s),cnt));
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<table[i];j++) avail[i].push(0);
        }
        for(int i=0;i<3;i++){
            //each kind of table are seperate
            while(!diner[i].empty()){
                int t = diner[i].front().first, x = diner[i].front().second;
                diner[i].pop();
                int at = avail[i].top();
                if(at-t>30) continue;
                //printf("table %d avail %d diner %d\n",i,at,t);
                tot += x;
                avail[i].pop();
                avail[i].push(max(t,at)+30);
            }
        }
        printf("%d\n",tot);
        
    }
    return 0;
}
