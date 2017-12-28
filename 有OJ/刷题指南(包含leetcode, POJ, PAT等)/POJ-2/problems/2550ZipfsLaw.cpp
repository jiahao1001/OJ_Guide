#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <ctype.h>
#include <queue>
using namespace std;
int main(){
    int n;
    bool first = true;
    while(scanf("%d",&n)!=EOF){
       if(first) first = false;
        else cout<<endl;
        map<string,int> freq;
        string line;
        int begin = false;
        while(getline(cin,line),line!="EndOfText"){
            begin = false;
            string word = "";
            for(int i=0;i<line.size();i++){
                char &c = line[i];
                if(begin){
                    if(isalpha(c)) word+=tolower(c);
                    else {
                        //cout<<word<<endl;
                        freq[word]++, word="",begin =false;
                    }
                }else{
                    if(isalpha(c)) word+=tolower(c), begin = true;
                }
            }
            if(word!="") {
                //cout<<word<<endl;
                freq[word]++;
                word="";
            }
        }
        //cout<<"Line "<<line<<endl;
        int cnt = 0;
        for(map<string,int>::iterator it = freq.begin();it!=freq.end();it++){
            if(it->second==n) cout<<it->first<<endl,cnt++;
        }
        if(!cnt) cout<<"There is no such word."<<endl;
        
    }
    return 0;
}
