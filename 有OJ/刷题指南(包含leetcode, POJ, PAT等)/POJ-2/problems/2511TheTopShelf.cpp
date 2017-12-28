#include<iostream>
#include<string.h>
#include<string>
#include<utility>
#include<vector>
#include<ctype.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
typedef pair<string,pair<int,int> > psii;
const int N = 2510;
psii book[N];
string title[N];
int n;
string trim(const string& s){
    string r = "";
    for(int i=0;i<s.size();i++)
        if(isalpha(s[i])) r+=tolower(s[i]);
    return r;
}
int dp[N][11];
inline bool diff(int i,int j){
    string&s1 = book[i].first, &s2 = book[j].first;
    for(int i=0;i<s1.size() && i<s2.size();i++)
        if(s1[i]==s2[i]) return false;
    return true;
}
int dc[N][11];
vector<int> shelf;
void bt(int i,int j){
    if(i<0) return;
    shelf.push_back(i);
    bt(dc[i][j],j-1);
}
vector<string> final;
int main()
{
    cin>>n;
    int v;
    string s;
    for(int i=0;i<n;i++){
        cin>>v;
        getline(cin,s);
        s = s.substr(1);
        book[i] = make_pair(trim(s),make_pair(i,v));
        title[i] = s;
    }
    sort(book,book+n);
    for(int i=0;i<n;i++)
        for(int j=1;j<=10;j++){
            v = book[i].second.second;
            dp[i][j] = v;
            dc[i][j] = -1;
            for(int k=0;k<i;k++){
                if(dp[k][j-1]+v>dp[i][j] && diff(k,i)){
                    if(dp[k][j-1]+v>dp[i][j]) dp[i][j] = dp[k][j-1]+v, dc[i][j] = k;
                }
            }
        }
    int ans = 0,ii;
    for(int i=0;i<n;i++) {
        if(dp[i][10]>ans) ans = dp[i][10], ii=i;
        ans = max(ans,dp[i][10]);
    }
    bt(ii,10);
    printf("%d\n",(int)shelf.size());
    printf("%d\n",ans);
    for(int i=0;i<shelf.size();i++){
        int id = book[shelf[i]].second.first;
        final.push_back(title[id]);
    }
    sort(final.begin(),final.end());
    for(int i=0;i<final.size();i++)
        cout<<final[i]<<endl;
    return 0;
}
