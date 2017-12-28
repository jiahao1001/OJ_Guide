#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
#include<string>
using namespace std;
string a;
char tem[3010];
int n;
string dfs(int i){
    vector<string> v;
    while(i<n && a[i]!='1'){
        v.push_back('0'+dfs(i+1));
        i+=v.back().size();
    }
    string r;
    sort(v.begin(),v.end());
    for(int k=0;k<v.size();k++)
        r+=v[k];
    return r+'1';
}
int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%s",tem);
        
        a = tem;
        n = a.size();
        string aa = dfs(0);
        scanf("%s",tem);
        a = tem;
        n = a.size();
        string bb = dfs(0);
        if(aa==bb) printf("same\n");
        else printf("different\n");
    }
    return 0;
}
