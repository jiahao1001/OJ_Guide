#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<ctype.h>
#include<vector>
using namespace std;
int k,n;
string key[20];
struct Excuse{
    string e;
    int i;
    int bad;
    Excuse(int _i,string _e){
        e = _e;
        i = _i;
        bad = 0;
        for(int i=0;i<_e.size();i++)
            if(!isalpha(_e[i])) _e[i]=' ';
            else _e[i] = tolower(_e[i]);
        istringstream is(_e);
        string word;
        while(is>>word){
            if(binary_search(key,key+k,word)) bad++;
        }
    }
};
bool operator<(const Excuse &e1, const Excuse &e2){
    if(e1.bad==e2.bad)return e1.i<e2.i;
    return e1.bad>e2.bad;
}
int main()
{
    int q=1;
    string line;
    while(cin>>k>>n){
        vector<Excuse> excuses;
        for(int i=0;i<k;i++)
            cin>>key[i];
        sort(key,key+k);
        getline(cin,line);
        for(int i=0;i<n;i++){
            getline(cin,line);
            excuses.push_back(Excuse(i,line));
        }
        sort(excuses.begin(),excuses.end());
        cout<<"Excuse Set #"<<q++<<endl;
        int k = excuses[0].bad;
        for(int i=0;i<n;i++)
            if(excuses[i].bad==k) cout<<excuses[i].e<<endl;
        cout<<endl;
    }
    return 0;
}

