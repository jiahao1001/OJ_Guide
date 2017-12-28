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
#include <queue>
using namespace std;
const int N = 360;
int n;
string a,b;
map<string,int> ids;
vector<int> g[N];
stack<int> S;

int visited[N];
int cnt;
void dfs(int i){
    visited[i]=1;
    for(int j=0;j<g[i].size();j++){
        int v=g[i][j];
        if(!visited[v]) dfs(v);
    }
    S.push(i);
}
int main(){
    int T;
    scanf("%d",&T);
    int q=1;
    while(T--){
        ids.clear();
        for(int i=0;i<N;i++) g[i].clear();
        memset(visited,0,sizeof(visited));
        cnt = 0;
        scanf("%d",&n);
        vector<string> names(n);
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            if(!ids.count(a)) {
                ids[a]=cnt++;
                names[cnt-1]=a;
            }
            if(!ids.count(b)) {
                ids[b]=cnt++;
                names[cnt-1]=b;
            }
            g[ids[a]].push_back(ids[b]);
            //g[ids[b]].push_back(ids[a]);
        }
        for(int i=0;i<cnt;i++){
            if(!visited[i]) dfs(i);
        }
        
        printf("Scenario #%d:\n",q++);
        while(!S.empty()){
            cout<<names[S.top()]<<endl;
            S.pop();
        }
        printf("\n");
    }
}
