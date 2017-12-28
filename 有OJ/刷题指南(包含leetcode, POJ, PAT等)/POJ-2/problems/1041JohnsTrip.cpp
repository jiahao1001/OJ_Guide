#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
using namespace std;
struct Street{
    int v,id;
    Street(){}
    Street(int _v,int _id):v(_v),id(_id){}
};
int drived[2000];
vector<Street> g[50];
stack<int> route;
int x,y,z;
int start;
void euler(int u){
    for(int i=0;i<g[u].size();i++){
        Street &e = g[u][i];
        if(!drived[e.id]){
            drived[e.id] = 1;
            euler(e.v);
            route.push(e.id);
        }
    }
}
int main()
{
    while(scanf("%d%d",&x,&y), x||y){
        start = min(x,y);
        for(int i=1;i<=44;i++) g[i].clear();
        memset(drived,0,sizeof(drived));
        scanf("%d",&z);
        g[x].push_back(Street(y,z));
        g[y].push_back(Street(x,z));
        while(scanf("%d%d",&x,&y),x||y){
            scanf("%d",&z);
            g[x].push_back(Street(y,z));
            g[y].push_back(Street(x,z));
        }
        bool odd = false;
        int total = 0;
        for(int i=1;i<=44;i++) {
            if(g[i].size()%2) odd = true;
            total+=g[i].size();
        }
        if(odd){
            printf("Round trip does not exist.\n");
            continue;
        }
        while(!route.empty()) route.pop();
        euler(start);
        if(route.size()!=total/2){
            printf("Round trip does not exist.\n");
            continue;
        }
        printf("%d",route.top());
        route.pop();
        while(!route.empty()) printf(" %d",route.top()),route.pop();
        printf("\n");
    }
}
