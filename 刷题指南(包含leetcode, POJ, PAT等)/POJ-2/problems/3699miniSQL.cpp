#include<iostream>
#include<map>
#include<string.h>
#include<string>
#include<stdio.h>
#include<sstream>
#include<vector>
using namespace std;
struct Field{
    string type;
    string name;
}fields[10];
struct Cell{
    int i;
    string s;
};
int m,n,k;
Cell table[10000][10];
map<string,int> meta;//field name -> column no)
struct Pred{
    string lhs,rhs;
    string op;
    int cid;
    Pred(string cond){
        int k = 0;
        for(int i=0;i<cond.size();i++)
            if(cond[i]=='='||cond[i]=='<'||cond[i]=='>'){
                op = cond[i];
                k = i;
                break;
            }
        lhs = cond.substr(0,k);
        rhs = cond.substr(k+1);
        int len = rhs.size();
        if(rhs[0]=='"') rhs=rhs.substr(1,len-2);
        cid = meta[lhs];
    }
    bool sat(int rid){
        //record rid satisfiable?
        Cell &cell = table[rid][cid];
        if(fields[cid].type=="INT"){
            int n = atoi(rhs.c_str());
            if(op=="=") return cell.i==n;
            else if(op==">") return cell.i>n;
            else return cell.i<n;
        }else{
            return cell.s==rhs;
        }
    }
};
char buf[20];
inline int intlen(int x){
    sprintf(buf,"%d",x);
    return strlen(buf);
}
inline void query(string sql){
    
    istringstream is(sql);
    string select,clist,where,cond;
    is>>select>>clist>>where>>cond;
    for(int i=0;i<clist.size();i++)
        if(clist[i]==',')clist[i]=' ';
    istringstream in(clist);
    string col;
    vector<int> ilist;
    vector<int> clen;
    while(in>>col) ilist.push_back(meta[col]),clen.push_back(0);
    for(int i=0;i<ilist.size();i++)
        clen[i] = fields[ilist[i]].name.size()+2;
    Pred pred(cond);
    
    for(int i=0;i<n;i++)
        if(pred.sat(i)){
            for(int k=0;k<ilist.size();k++){
                int j = ilist[k];
                if(fields[j].type=="STR") clen[k] = max(clen[k],(int)table[i][j].s.size()+2);
                else clen[k]=max(clen[k],intlen(table[i][j].i)+2);
            }
        }
    int totlen = 0;
    for(int i=0;i<clen.size();i++) totlen+=clen[i];
    totlen+=clen.size()+1;
    cout<<"+";
    cout<<string(totlen-2,'-');
    cout<<"+"<<endl;
    cout<<"|";
    //do padding for column name and |
    for(int i=0;i<ilist.size();i++){
        int j = ilist[i];
        //cout<<"clen "<<clen[i]<<endl;
        int padding = clen[i]-fields[j].name.size();
        //cout<<"pad"<<padding<<endl;
        int left = padding/2;
        int right = padding-left;
        cout<<string(left,' ');
        cout<<fields[j].name;
        cout<<string(right,' ');
        cout<<"|";
    }
    cout<<endl;
    cout<<"|";
    for(int i=0;i<clen.size();i++)
        cout<<string(clen[i],'-')<<"|";
    cout<<endl;
    for(int i=0;i<n;i++)
        if(pred.sat(i)){
            cout<<"|";
            for(int k=0;k<ilist.size();k++){
                int j = ilist[k];
                int len;
                if(fields[j].type=="STR") len = table[i][j].s.size();
                else len=intlen(table[i][j].i);
                int padding = clen[k] - len;
                int left = padding/2;
                int right = padding-left;
                cout<<string(left,' ');
                if(fields[j].type=="STR")cout<<table[i][j].s;
                else cout<<table[i][j].i;
                cout<<string(right,' ');
                cout<<"|";
            }
            cout<<endl;
        }
        
        
        
        
    cout<<"+";
    cout<<string(totlen-2,'-');
    cout<<"+"<<endl<<endl;
}
int main()
{
    cin>>m>>n>>k;
    for(int i=0;i<m;i++)
        cin>>fields[i].name>>fields[i].type;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(fields[j].type=="INT") cin>>table[i][j].i;
            else cin>>table[i][j].s;
    }
    //build meta
    for(int i=0;i<m;i++)
        meta[fields[i].name] = i;
    //query
    string sql;
    getline(cin,sql);
    for(int i=0;i<k;i++){
        getline(cin,sql);
        query(sql);
    }
    return 0;
}
