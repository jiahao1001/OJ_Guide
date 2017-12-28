
#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int t;
struct Event{
    bool hired;
    int t,i;
} e[24];
bool operator<(const Event &e1, const Event& e2){
    if(e1.t==e2.t){
        return e1.hired;
    }
    return e1.t<e2.t;
}
vector<int> hall[12];
int dp[24][1<<8];
int main(){
    scanf("%d",&t);
    int R;
    while(t--){
        scanf("%d",&R);
        int a,b,cnt,tmp;
        for(int i=0;i<R;i++){
            hall[i].clear();
            scanf("%d%d",&a,&b);
            scanf("%d",&cnt);
            e[2*i].t = a;
            e[2*i].hired = true;
            e[2*i].i = i;
            e[2*i+1].t = b;
            e[2*i+1].hired = false;
            e[2*i+1].i = i;
            for(int j=0;j<cnt;j++){
                scanf("%d",&tmp);
                hall[i].push_back(tmp-1);
            }
        }
        memset(dp,0,sizeof dp);
        sort(e,e+2*R);
        for(int i=0;i<hall[e[0].i].size();i++)
            dp[0][1<<hall[e[0].i][i]] = 1;
        int x;
        for(int i=0;i<2*R-1;i++)
            for(int j=0;j<(1<<8);j++){
                if(!dp[i][j]) continue;
                x = e[i+1].i;
                for(int k=0;k<hall[x].size();k++){
                    int y = 1<<hall[x][k];
                    if(e[i+1].hired){
                        if((j^y) > j) dp[i+1][j^y]=1;
                    }else{
                        if((j^y)<j) dp[i+1][j^y]=1;
                    }
                }
            }
        if(dp[2*R-1][0]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
