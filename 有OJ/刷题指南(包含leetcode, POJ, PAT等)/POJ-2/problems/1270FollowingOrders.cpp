#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
vector<char> alpha;
int g[26][26];
int degree[26];
int vis[26];
char path[30];
map<char,int> id;
void dfs(int cur){
    if(cur==alpha.size()){
        path[cur] = 0;
        printf("%s\n",path);
        return;
    }
    for(int i=0;i<alpha.size();i++){
        if(!vis[i] && degree[i]==0){
            //remove i
            vis[i] = 1;
            for(int j=0;j<alpha.size();j++)
                if(!vis[j] && g[i][j]) degree[j]--;
            path[cur]=alpha[i];
            dfs(cur+1);
            for(int j=0;j<alpha.size();j++)
                if(!vis[j] && g[i][j]) degree[j]++;
            vis[i] = 0;
            //resume i
        }
    }
}
int main()
{
    string line;
    bool begin = true;
    while(getline(cin,line)){
        istringstream is(line);
        alpha.clear();
        char a,b,c;
        while(is>>c) alpha.push_back(c);
        sort(alpha.begin(),alpha.end());
        id.clear();
        for(int i=0;i<alpha.size();i++)
            id[alpha[i]] = i;
        getline(cin,line);
        istringstream iis(line);
        memset(degree,0,sizeof degree);
        memset(g,0,sizeof g);
        memset(vis,0,sizeof vis);
        while(iis>>a>>b) g[id[a]][id[b]] = 1, degree[id[b]] ++;
        dfs(0);
        printf("\n");
    }
    return 0;
}
