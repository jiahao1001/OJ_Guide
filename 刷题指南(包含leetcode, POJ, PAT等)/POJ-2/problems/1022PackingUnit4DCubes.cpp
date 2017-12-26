#include<iostream>
#include<stdio.h>
#include<map>
#include<limits.h>
using namespace std;
int mark[120];
int n;
int adj[120][8];
map<int,int> id;
int d[8][4]={{-1,0,0,0},
             {1,0,0,0},
             {0,-1,0,0},
             {0,1,0,0},
             {0,0,-1,0},
             {0,0,1,0},
             {0,0,0,-1},
             {0,0,0,1}};
int x1_min,x1_max,x2_min,x2_max,x3_min,x3_max,x4_min,x4_max;
void dfs(int i,int x1,int x2,int x3,int x4){
    x1_min = min(x1,x1_min);
    x1_max = max(x1,x1_max);
    x2_min = min(x2,x2_min);
    x2_max = max(x2,x2_max);
    x3_min = min(x3,x3_min);
    x3_max = max(x3,x3_max);
    x4_min = min(x4,x4_min);
    x4_max = max(x4,x4_max);
    
    mark[i] = 1;
    for(int j=0;j<8;j++){
        int nxt = adj[i][j];
        if(!nxt) continue;
        if(!mark[nxt]){
            dfs(nxt,x1+d[j][0],x2+d[j][1],x3+d[j][2],x4+d[j][3]);
        }
    }
}
bool symmetry(){
    for(int i=1;i<=n;i++)
        for(int j=0;j<8;j++){
            int nei = adj[i][j];
            if(!nei) continue;
            if(i!=adj[nei][j^1]) {
                //printf("(%d,%d)\n",i,nei);
                return false;
            }
        }
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        id.clear();
        scanf("%d",&n);
        memset(adj,0,sizeof adj);
        int cnt = 1;
        for(int i=1;i<=n;i++){
            int ii;
            scanf("%d",&ii);
            if(!id.count(ii)) id[ii] = cnt++;
            int c = id[ii];
            for(int j=0;j<8;j++){
                scanf("%d",&ii);
                if(!ii)continue;
                if(!id.count(ii)) id[ii] = cnt++;
                adj[c][j] = id[ii];
            }
        }
        //check symmetry
        if(!symmetry()){
            printf("Inconsistent\n");
            continue;
        }
        
        x1_min = x2_min = x3_min = x4_min = INT_MAX;
        x1_max = x2_max = x3_max = x4_max = INT_MIN;
        memset(mark,0,sizeof mark);
        dfs(1,0,0,0,0);
        bool ok = true;
        for(int i=1;i<=n;i++)
            if(!mark[i]) ok = false;
        if(!ok)printf("Inconsistent\n");
        else printf("%d\n",(x1_max-x1_min+1)*(x2_max-x2_min+1)*(x3_max-x3_min+1)*(x4_max-x4_min+1));
    }
    return 0;
}
