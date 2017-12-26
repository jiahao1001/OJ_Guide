#include<ctype.h>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<stdlib.h>
#include<sstream>
using namespace std;
int n,m;
vector<vector<string> > sheet;
vector<vector<int> > v;
vector<vector<int> > done;
int f(int i,int j);
int col(string s){
    int x=0;
    for(int i=0;i<s.size();i++){
        x = x*26;
        if(i==s.size()-1) x+=s[i]-'A';
        else x+=s[i]-'A'+1;
    }
    return x;
}
int compute(string token){
    string c="";
    int r=0;
    int len = token.size();
    for(int i=0;i<len;i++){
        if(isalpha(token[i])) c+=token[i];
        else r = r*10 + token[i]-'0';
    }
    return f(r-1,col(c));
}
int f(int i,int j){
    if(done[i][j]) return v[i][j];
    v[i][j] = 0;
    if(sheet[i][j][0]=='='){
        string s = sheet[i][j].substr(1);
        istringstream is(s);
        string token;
        while(getline(is,token,'+')){
            v[i][j] += compute(token);
        }
    }else v[i][j] = atoi(sheet[i][j].c_str());
    
    done[i][j] = 1;
    return v[i][j];
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>m>>n;
        sheet = vector<vector<string> >(n,vector<string>(m,""));
        v = vector<vector<int> >(n,vector<int>(m,0));
        done = vector<vector<int> >(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>sheet[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                cout<<f(i,j);
                if(j==m-1)cout<<endl;
                else cout<<" ";
            }
        
    }
    return 0;
}
