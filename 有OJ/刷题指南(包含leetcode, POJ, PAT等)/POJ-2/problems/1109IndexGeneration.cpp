#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<sstream>
#include<ctype.h>
using namespace std;
struct s_entry{
    //string key;
    set<int> pages;
};
struct entry{
    string key;
    set<int> pages;
    map<string,s_entry> secondary;
};
map<string,entry> ref1;
string trim(string s){
    int l = 0,r = s.size()-1;
    if(s[l]==' ')l++;
    if(s[r]==' ')r--;
    return  s.substr(l,r-l+1);
}
string low(string ss){
    for(int i=0;i<ss.size();i++)
        ss[i]=tolower(ss[i]);
    return ss;
}
inline void add_entry(string marker,int n){
    string p="",s="";
    //four cases
    if(marker.find_first_of('%')==string::npos && marker.find_first_of('$')==string::npos){
        //neither
        p = trim(marker);
    }else if(marker.find_first_of('%')==string::npos){
        //has text and secondary
        int pos = marker.find_first_of('$');
        p = trim(marker.substr(0,pos));
        s = trim(marker.substr(pos+1));
        
    }else if(marker.find_first_of('$')==string::npos){
        int pos = marker.find_first_of('%');
        p = trim(marker.substr(pos+1));
    }else{
        int p1 = marker.find_first_of('%');
        int p2 = marker.find_first_of('$');
        p = trim(marker.substr(p1+1,p2-p1-1));
        s = trim(marker.substr(p2+1));
    }
    if(s!=""){
        //add a secondary
        string pp = low(p);
        ref1[pp].key = p;
        ref1[pp].secondary[s].pages.insert(n);
    }else{
        string pp = low(p);
        ref1[pp].key = p;
        ref1[pp].pages.insert(n);
    }
}
int main()
{
    string line;
    int q=1;
    while(getline(cin,line),line!="**"){
        ref1.clear();
        cout<<"DOCUMENT "<<q++<<endl;
        string doc = line+" ";
        while(getline(cin,line),line!="*")
            doc+=line+" ";
        istringstream is(doc);
        string page;
        int cnt=0;
        int n=0;
        while(getline(is,page,'&')){
            n++;
            //in page n
            string mark ="";
            bool in = false;
            for(int i=0;i<page.size();i++){
                if(page[i]=='{') in = true;
                else if(page[i]=='}'){
                    add_entry(mark,n);
                    mark = "";
                    in = false;
                }else if(in) mark+=page[i];
            }
        }
        for(map<string,entry>::iterator it=ref1.begin();it!=ref1.end();it++){
            cout<<it->second.key;
            for(set<int>::iterator j = it->second.pages.begin();j!=it->second.pages.end();j++)
                cout<<", "<<*j;
            cout<<endl;
            for(map<string,s_entry>::iterator j = it->second.secondary.begin();j!=it->second.secondary.end();j++){
                cout<<"+ "<<j->first;
                for(set<int>::iterator k = j->second.pages.begin();k!=j->second.pages.end();k++)
                    cout<<", "<<*k;
                cout<<endl;
            }
        }
    }
    return 0;
}
