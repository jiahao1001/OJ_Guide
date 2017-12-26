#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;
string x,y;
int common(){
    int a = x.size(), b = y.size();
    // y[0] -> x[-(b-1)]
    // y[0] -> x[a-1];
    int ans = 0;
    for(int k=-b+1;k<a;k++){
        int cnt = 0;
        for(int i=0;i<b;i++){
            int j = i+k;
            if(j>=0 && j<a && x[j]==y[i]) cnt++;
        }
        ans = max(ans,cnt);
    }
    return ans;
    
}
int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}
int main(){
    while(cin>>x,x!="-1"){
        cin>>y;
        int m = x.size() + y.size();
        int n = common();
        cout<<"appx("<<x<<","<<y<<") = ";
        if(!n)cout<<0<<endl;
        else if(2*n==m) cout<<1<<endl;
        else {
            int g = gcd(2*n,m);
            cout<<2*n/g<<"/"<<m/g<<endl;
        }
    }
    return 0;
}
