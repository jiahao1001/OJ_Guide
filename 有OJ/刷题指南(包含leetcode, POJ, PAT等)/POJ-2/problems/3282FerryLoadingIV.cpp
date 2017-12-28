#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
#include<set>
using namespace std;
int main(){
    int t,l,m;
    cin>>t;
    while(t--){
        vector<int> car[2];
        int cnt[2];
        cnt[0] = cnt[1]=0;
        int cur = 0;
        cin>>l>>m;
        int x;
        string s;
        for(int i=0;i<m;i++){
            cin>>x>>s;
            if(s=="left") car[0].push_back(x);
            else car[1].push_back(x);
         }
        int ans = 0;
        while(cnt[0]<car[0].size() || cnt[1]<car[1].size()){
            int sum = 0;
            while(cnt[cur]<car[cur].size() && sum+car[cur][cnt[cur]]<=l*100)  sum+=car[cur][cnt[cur]],cnt[cur]++;
            cur = 1-cur;
            ans++;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
