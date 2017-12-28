#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<ctype.h>
#include<limits.h>
using namespace std;
const int INF = INT_MAX/2;
const int N = 1000;//max mail amount
map<string,int> cnt;
map<string,int> cnt1;
vector<string> bad_zip;
int dp[N+1];
inline bool valid(string zip){
    if(zip.size()!=5) return false;
    int sum = 0;
    for(int i=0;i<5;i++)
        if(!isdigit(zip[i])) return false;
        else sum+=zip[i]-'0';
    if(!sum) return false;
    return true;
}
int main()
{
    string zip;
    for(int i=0;i<=N;i++) dp[i] = INF;
    dp[0] = 0;
    for(int i=0;i<=N;i++)
        for(int w=10;w<=15;w++){
            if(i+w<=N)dp[i+w] = min(dp[i+w],dp[i]+1);
        }
    
    while(cin>>zip){
        if(!valid(zip)){
            if(!cnt.count(zip)) bad_zip.push_back(zip);
        }
        cnt[zip]++;
    }
    cout<<"ZIP         LETTERS     BUNDLES"<<endl<<endl;
    int total = 0,bundles = 0;
    for(map<string,int>::iterator it=cnt.begin();it!=cnt.end();it++){
        string zip = it->first;
        int x = it->second;
        if(!valid(zip)) continue;
        while(dp[x]==INF)x--;
        if(x) printf("%s%12d%12d\n",zip.c_str(),x,dp[x]),cnt[zip]-=x,total+=x,bundles+=dp[x];
    }
    cout<<endl;
    //collect 3-digit
    for(map<string,int>::iterator it=cnt.begin();it!=cnt.end();it++){
        string zip = it->first;
        int x = it->second;
        if(!valid(zip)||!x) continue;
        zip[3]='x',zip[4] = 'x';
        cnt1[zip]+=x;
    }
    //mail 3 digit
    for(map<string,int>::iterator it=cnt1.begin();it!=cnt1.end();it++){
        string zip = it->first;
        int x = it->second;
        while(dp[x]==INF)x--;
        if(x) printf("%s%12d%12d\n",zip.c_str(),x,dp[x]),cnt1[zip]-=x,total+=x,bundles+=dp[x];
    }
    cout<<endl;
    for(map<string,int>::iterator it=cnt.begin();it!=cnt.end();it++){
        string zip = it->first;
        int x = it->second;
        if(!valid(zip)||!x) continue;
        string zz = zip;
        zz[3]=zz[4] = 'x';
        if(cnt1[zz]!=0){
            x = min(x,cnt1[zz]);
            printf("%s%12d%12d\n",zip.c_str(),x,0),cnt1[zz]-=x,total+=x;
        }
    }
    cout<<endl;
    printf("TOTALS%11d%12d\n",total,bundles);
    cout<<endl;
    cout<<"INVALID ZIP CODES"<<endl;;
    cout<<endl;
    for(int i=0;i<bad_zip.size();i++)
        cout<<bad_zip[i]<<endl;
    return 0;
}
