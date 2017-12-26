#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
#include<float.h>
#include<math.h>
#include<sstream>
#include<stdlib.h>
#include<limits.h>
#include<string>
#include<assert.h>
#include<numeric>
#include<map>
using namespace std;
typedef pair<int,int> PII;
int t,n;
int A[12];
int cnt;
void dfs(int i,int sum,vector<PII> &path, vector<vector<PII> > &ans){
    if(i==n){
        if(sum==t)
            ans.push_back(path);
        return;
    }
    int j=i+1;
    while(j<n && A[j]==A[i]) j++;
    for(int k=j;k>=i;k--){
        if(k-i)path.push_back(make_pair(A[i],k-i));
        dfs(j,sum+A[i]*(k-i),path,ans);
        if(k-i)path.pop_back();
    }
}
void pretty_print(vector<PII> &V){
    bool first = true;
    for(int i=0;i<V.size();i++)
        for(int j=0;j<V[i].second;j++){
            if(first){
                first = false;
                printf("%d",V[i].first);
            }else printf("+%d",V[i].first);
        }
    printf("\n");
}
int main(){
    while(scanf("%d%d",&t,&n),n){
        for(int i=0;i<n;i++) scanf("%d",A+i);
        vector<vector<PII> > ans;
        vector<PII> path;
        dfs(0,0,path,ans);
        printf("Sums of %d:\n",t);
        if(!ans.size()) printf("NONE\n");
        else{
            for(int i=0;i<ans.size();i++)
                pretty_print(ans[i]);
        }
        
    }
    return 0;
}
