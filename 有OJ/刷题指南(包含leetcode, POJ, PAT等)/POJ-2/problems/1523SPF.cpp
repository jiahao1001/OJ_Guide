#include<iostream>
#include<map>
#include<set>
#include<string>
#include <vector>
#include <stdlib.h>
#include <climits>
#include <utility>
#include <stdio.h>
#include <assert.h>
#include <stack>
#include <string.h>
using namespace std;
const int N = 1010;
typedef pair<int,int> PII;
vector<PII> elist;
set<int> v;
int idx[N];
int real[N];
int dfn[N],low[N];
int tag[N];
int g[N][N];
int n;
int cnt;
void dfs(int u,int f){
    dfn[u]=low[u]=cnt++;
    int kid = 0;
    for(int i=0;i<n;i++)
        if(g[u][i] && i!=f){
            if(dfn[i]!=-1){
                if(dfn[i]<dfn[u])
                    low[u] = min(low[u],dfn[i]);
            }else if(dfn[i]==-1){
                dfs(i,u);
                low[u] = min(low[u],low[i]);
                kid++;
                if(u!=0 && low[i]>=dfn[u] || u==0 && kid>1) tag[u]++;
            }
        }
}
int main(){
    int q=1;
    int a,b;
    while(scanf("%d",&a),a){
        scanf("%d",&b);
        v.clear();
        v.insert(a);
        v.insert(b);
        elist.clear();
        elist.push_back(make_pair(a,b));
        while(scanf("%d",&a),a){
            scanf("%d",&b);
            elist.push_back(make_pair(a,b));
            v.insert(a);
            v.insert(b);
        }
        memset(idx,-1,sizeof(idx));
        n=0;
        for(set<int>::iterator it=v.begin();it!=v.end();it++){
            idx[*it]=n++;
            real[n-1] = *it;
        }
        memset(g,0,sizeof(g));
        memset(tag,0,sizeof(tag));
        memset(dfn,-1,sizeof(dfn));
        memset(low,-1,sizeof(low));
        for(int i=0;i<elist.size();i++)
        {
            a=elist[i].first;
            b=elist[i].second;
            a=idx[a];
            b=idx[b];
            g[a][b] = g[b][a] = 1;
        }
        cnt = 0;
        dfs(0,-1);
        printf("Network #%d\n",q++);
        int spf = 0;
        for(int i=0;i<n;i++)
            if(tag[i]) printf("  SPF node %d leaves %d subnets\n",real[i],tag[i]+1),spf++;
        if(!spf) printf("  No SPF nodes\n");
        printf("\n");
    }
    return 0;
}
