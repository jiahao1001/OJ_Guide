#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
using namespace std;
typedef map<string,multiset<string> > M;
M anagram;
struct Wrap{
    multiset<string> w;
};
void dfs(priority_queue<Wrap> &pq){
    if(pq.empty())return;
    Wrap w = pq.top();
    pq.pop();
    dfs(pq);
    cout<<"Group of size "<<w.w.size()<<":";
    string last = "";
    for(multiset<string>::iterator i = w.w.begin();i!=w.w.end();i++){
        if(*i !=last) cout<<" "<<*i, last = *i;
    }
    cout<<" ."<<endl;
}
bool operator<(const Wrap &x, const Wrap &y){
    if(x.w.size()==y.w.size()){
        return *(x.w.begin())<*(y.w.begin());
    }
    return x.w.size()>y.w.size();
}
int main(){
    string word,key;
    while(cin>>word){
        key = word;
        sort(key.begin(),key.end());
        anagram[key].insert(word);
    }
    priority_queue<Wrap> pq;
    for(M::iterator i=anagram.begin();i!=anagram.end();i++){
        Wrap w;
        w.w = i->second;
        pq.push(w);
        if(pq.size()>5) pq.pop();
    }
    dfs(pq);
    return 0;
}
