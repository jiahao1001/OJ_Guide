#include<vector>
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
#include<sstream>
using namespace std;
string line;
bool empty(const string &line){
    for(int i=0;i<line.size();i++)
        if(line[i]!=' ') return false;
    return true;
}
int cut;
int reff_no(string& line){
    if(!line.size() || line[0]!='[') return -1;
    int id = 0;
    for(int i=1;i<line.size();i++){
        if(line[i]==']') {
            cut = i+1;
            break;
        }
        id = id*10 + (line[i]-'0');
    }
    return id;
}
map<int,int> renum;
int re[1000];
vector<string> reff;
int main()
{
    bool in_reff = false;
    bool in_para = false;
    int p_cnt = 0;
    int num = 0;
    int id = 0;
    int last = 0;
    reff = vector<string>(1000,"");
    while(getline(cin,line)){
        num = reff_no(line);
        if(empty(line)){
            //empty end a para or reff
            if(in_para) p_cnt++;
            in_para = in_reff = false;
        }else if(in_para || num==-1){
            if(in_reff){
                reff[last]+="\n"+line;
            }else{
                if(!in_para){
                    //begin a para
                    if(p_cnt) cout<<endl;
                    in_para = true;
                }
                int n = 0;
                bool in = false;
                for(int i=0;i<line.size();i++){
                    if(in){
                        if(line[i]==']'){
                            if(!renum.count(n)) renum[n] = ++id;
                            cout<<renum[n];
                            in = false, n = 0;
                            cout<<"]";
                        }else{
                            n = n*10 + line[i]-'0';
                        }
                    }else{
                        if(line[i]=='[') in = true;
                        cout<<line[i];
                    }
                }
                cout<<endl;
            }
            
        }else if(num!=-1){
            //begin of a reff
            in_reff = true;
            last = num;
            reff[num] = line.substr(cut);
        }
    }
    if(in_reff) p_cnt++;
    in_reff = in_para = false;
    for(map<int,int>::iterator it = renum.begin();it!=renum.end();it++){
        re[it->second] = it->first;
    }
    for(int i=1;i<=id;i++){
        if(p_cnt)cout<<endl;
        cout<<"["<<i<<"]"<<reff[re[i]]<<endl;
        p_cnt++;
    }
    return 0;
}
