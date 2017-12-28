#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;
string F = "AEHIJLMOSTUVWXYZ12358";
string B = "A3HILJMO2TUVWXY51SEZ8";
string word;
bool is_palindrome(){
    int n = word.size();
    for(int i=0;i<n/2;i++)
        if(word[i]!=word[n-1-i]) return false;
    return true;
}
char rev(char c){
    int x = F.find(c);
    if(x==string::npos) return ' ';
    else return B[x];
}
bool is_mirror(){
    int n = word.size();
    for(int i=0;i<n;i++)
        if(rev(word[i])!=word[n-1-i]) return false;
    return true;
}
int main(){
    while(cin>>word){
        cout<<word<<" -- ";
        bool palindrome = is_palindrome(), mirror = is_mirror();
        if(!palindrome){
            if(!mirror) cout<<"is not a palindrome."<<endl;
            else cout<<"is a mirrored string."<<endl;
        }else{
            if(!mirror) cout<<"is a regular palindrome."<<endl;
            else cout<<"is a mirrored palindrome."<<endl;
        }
        cout<<endl;
    }
    return 0;
}
