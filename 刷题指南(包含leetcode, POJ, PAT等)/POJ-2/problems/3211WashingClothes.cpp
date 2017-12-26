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
#include<stdlib.h>
#include<limits.h>
#include<string>
#include<numeric>
#include<map>
using namespace std;
const int N = 100010;
int m,n;
int dp[N];
int shortest(vector<int> &V){
    if(V.size()==0) return 0;
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    int total = accumulate(V.begin(),V.end(),0);
    //cout<<total<<" total"<<endl;
    for(int i=0;i<V.size();i++){
        for(int j=total;j>=0;j--)
            if(dp[j] && j+V[i]<=total) dp[j+V[i]] = 1;
    }
    int result = INT_MAX;
    for(int i=0;i<=total;i++)
        if(dp[i]) result = min(result,max(i,total-i));
    //cout<<result<<" result"<<endl;
    return result;
    
}
int main()
{
    string color;
    int t;
    while(cin>>m>>n,m||n){
        map<string,int> id;
        vector<int> V[10];
        for(int i=0;i<m;i++){
            cin>>color;
            id[color]=i;
        }
        for(int i=0;i<n;i++){
            cin>>t>>color;
            V[id[color]].push_back(t);
            //cout<<color<<endl;
            //cout<<"G"<<endl;
        }
        //cout<<"G";
        int total = 0;
        for(int i=0;i<m;i++) total+=shortest(V[i]);
        cout<<total<<endl;
    }
    return 0;
}
