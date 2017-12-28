#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
#include<map>
#include<string>
#include<sstream>
#include<math.h>
#include<ctype.h>
using namespace std;

inline vector<string> get_terms(string s){
    istringstream in(s);
    string raw_term,term;
    vector<string> terms;
    while(in>>raw_term){
        term="";
        for(int i=0;i<raw_term.size();i++){
            if(isalpha(raw_term[i])||isdigit(raw_term[i])) term+=tolower(raw_term[i]);
        }
        if(term!="") terms.push_back(term);
    }
    return terms;
}
int main()
{
    string line;
    vector<string> search_terms;
    map<string,int> search;
    while(true){
        getline(cin,line);
        vector<string> terms = get_terms(line);
        for(int i=0;i<terms.size();i++)
        {
            //cout<<terms[i]<<endl;
            search_terms.push_back(terms[i]);
        }
        if(line=="----------") break;
    }
    for(int i=0;i<search_terms.size();i++)
        search[search_terms[i]]++;
    while(true){
        int cnt = 0;
        vector<string> document_terms;
        map<string,int> document;
        while(true){
            getline(cin,line);
            if(line=="----------") break;
            vector<string> terms = get_terms(line);
            for(int i=0;i<terms.size();i++) document_terms.push_back(terms[i]);
            cnt++;
        }
        if(cnt==0) break;
        //calculate the score
        for(int i=0;i<document_terms.size();i++) document[document_terms[i]]++;
        double score = 0;
        for(map<string,int>::iterator it = search.begin();it!=search.end();it++){
            int t_score = it->second*document[it->first];
            //cout<<t_score<<endl;
            score += sqrt(1.0*t_score);
        }
        printf("%.2f\n",score);
        
    }
    
    return 0;
}
