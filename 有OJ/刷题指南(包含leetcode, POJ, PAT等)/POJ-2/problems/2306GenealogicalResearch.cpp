#include<iostream>
#include<string>
#include<sstream>
#include<stdio.h>
#include<map>
#include<vector>
#include<set>
using namespace std;
map<string,int> id; // name -> id
int cnt;
vector<string> d1,d2; //birth, death
vector<int> m,f;//mother , father
vector<string> name;
struct I{
    int i;
    I(){}
    I(int _i):i(_i){}
};
bool operator<(const I &i1,const I &i2){
    return name[i1.i]<name[i2.i];
}
vector<set<I> > son;

string trim(string s){
    int l=0,r=s.size()-1;
    while(s[l]==' ')l++;
    while(s[r]==' ')r--;
    return s.substr(l,r-l+1);
}
void add_id(string s){
    if(id.count(s)) return;
    id[s] = cnt;
    name.push_back(s);
    d1.push_back(""); // birth 
    d2.push_back(""); // death
    m.push_back(-1); // mother, unspecified
    f.push_back(-1);
    son.push_back(set<I>());
    cnt ++;
}
void print_A(int ind,int i){
    cout<<string(ind,' ')<<name[i];
    if(d1[i]==""){
        cout<<endl;
        return;
    }
    cout<<" "<<d1[i]<<" -";
    if(d2[i]!="")cout<<" "<<d2[i];
    cout<<endl;
    int j = m[i],k = f[i];
    if(name[j]>name[k]) swap(j,k);
    print_A(ind+2,j);
    print_A(ind+2,k);
}
void print_D(int ind,int i){
    cout<<string(ind,' ')<<name[i];
    if(d1[i]==""){
        cout<<endl;
        return;
    }
    cout<<" "<<d1[i]<<" -";
    if(d2[i]!="")cout<<" "<<d2[i];
    cout<<endl;
    set<I> & ss = son[i];
    for(set<I>::iterator it = ss.begin();it!=ss.end();it++){
        print_D(ind+2,it->i);
    }
}
int main()
{
    string cmd;
    string line;
    string token[4];
    cnt = 0;
    bool begin = true;
    while(cin>>cmd,cmd!="QUIT"){
        getline(cin,line);
        line += " ";
        istringstream is(line);
        if(cmd=="BIRTH"){
            for(int i=0;i<4;i++)
                getline(is,token[i],':');
            for(int i=0;i<4;i++){
                token[i] = trim(token[i]);
                if(i!=1) add_id(token[i]);
            }
            //add birth and mother, father
            int i = id[token[0]];
            int j = id[token[2]];//mother id
            int k = id[token[3]];
            d1[i] = token[1]; // birth day
            m[i] = j, f[i] = k;
            //both mother and father add a son
            son[j].insert(I(i));
            son[k].insert(I(i));
            
        }else if(cmd=="DEATH"){
            for(int i=0;i<2;i++)
                getline(is,token[i],':'),token[i] = trim(token[i]);
            add_id(token[0]);
            int i = id[token[0]];
            d2[i] = token[1];
        }else if(cmd=="ANCESTORS"){
            if(begin) begin = false;
            else cout<<endl;
            getline(is,token[0]);
            token[0] = trim(token[0]);
            cout<<"ANCESTORS of "<<token[0]<<endl;
            if(!id.count(token[0])) continue;
            int i = id[token[0]];
            int j = m[i],k = f[i];
            if(name[j]>name[k]) swap(j,k);
            print_A(2,j);
            print_A(2,k);
            
        }else{
            if(begin) begin = false;
            else cout<<endl;
            getline(is,token[0]);
            token[0] = trim(token[0]);
            cout<<"DESCENDANTS of "<<token[0]<<endl;
            if(!id.count(token[0])) continue;
            int i = id[token[0]];
            set<I> & ss = son[i];
            for(set<I>::iterator it = ss.begin();it!=ss.end();it++){
                print_D(2,it->i);
            }
        }
    }
    return 0;
}
