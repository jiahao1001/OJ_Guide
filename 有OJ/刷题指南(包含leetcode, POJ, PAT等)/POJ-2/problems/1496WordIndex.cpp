#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <climits>
using namespace std;
int dp[6][26];
int f(int i,int c){
    if(i==1) return dp[i][c] = 1;
    if(dp[i][c]!=-1) return dp[i][c];
    dp[i][c] = 0;
    for(int c1=c+1;c1<=26-i;c1++)
        dp[i][c]+=f(i-1,c1);
    return dp[i][c];
    
}
inline bool valid(string word){
    for(int i=1;i<word.size();i++)
        if(word[i]<=word[i-1]) return false;
    return true;
}
inline int calc(string word){
    int n = word.size();
    int total = 0;
    for(int i=n-1;i>=1;i--){
        for(char c='a';c<='z'-i;c++)
            total+=f(i,c-'a');
    }
    
    for(int i=0;i<n;i++){
        for(char c='a';c<word[i];c++){
            total += f(n-i,c-'a');
        }
    }
    return total+1;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    string word;
    while(cin>>word){
        if(!valid(word)) cout<<0<<endl;
        else{
            cout<<calc(word)<<endl;
        }
    }
    return 0;
}
