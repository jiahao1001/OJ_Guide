#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<sstream>
#include<string.h>
using namespace std;
typedef basic_string<unsigned char> ustring;
//if contain '─' not a text line
unsigned char ccc[]={
    179, 196, // '│' '─'
    218, 194, 191, // '┌' '┬' '┐'
    195, 197, 180, // '├' '┼' '┤'
    192, 193, 217, // '└' '┴' '┘'
};


int col;
unsigned char line[300];
inline int ustrlen(unsigned char *s){
    int len = 0;
    while(s[len]!=0) len++;
    return len;
}
vector<vector<vector<unsigned char *> > > table;
unsigned char* trim(unsigned char* token){
    int len;
    for(len=0;token[len]!=0;len++){}
    int l=0,r=len-1;
    while(l<len && token[l]==' ') l++;
    while(r>=0 && token[r]==' ') r--;
    if(l>r) {
        unsigned char *ret = (unsigned char *)malloc(1*sizeof(unsigned char));
        ret[0] = 0;
        return ret;
    }
    unsigned char *ret = (unsigned char*)malloc((r-1+2)*sizeof(unsigned char));
    for(int i=0;i<=r-1+1;i++)
        ret[i] = token[l+i];
    ret[r-l+1] = 0;
    return ret;
}
inline void print_cell(int i,int j,int k,int w){
    if(table[i][j].size()>k){
        cout<<" ";
        int len = ustrlen(table[i][j][k]);
        for(int l=0;l<len;l++) cout<<table[i][j][k][l];
        w-=len+1;
    }
    for(int l=0;l<w;l++)
        cout<<" ";
    return;
}
int main()
{
    unsigned char c;
    col = 0;
    while(cin>>std::noskipws>>c,c!=10){
        if(c==194) col++;
    }
    col+=1;
    vector<vector<unsigned char*> > row;
    while(cin>>std::noskipws>>c){
        line[0] = c;
        int lc = 0;
        int sz = 1;
        while(cin>>std::noskipws>>c) {
            if(c==10) break;
            line[sz++] = c;
        }
        bool bad = false;
        for(int i=0;i<sz;i++)
            if(line[i]==196) {
                bad = true;
                break;
            }
        if(bad) {
            table.push_back(row);
            row.clear();
        }else{
            unsigned char token[300];
            int t_sz=0;
            int cnt = 0;
            for(int i=1;i<sz;i++){
                if(line[i]==179){
                    if(cnt==row.size()) row.push_back(vector<unsigned char*>());
                    token[t_sz] = 0;
                    row[cnt].push_back(trim(token));
                    t_sz = 0;
                    cnt++;
                }else token[t_sz++]=line[i];
            }
        }
    }
    //calculate the width
    vector<int> width(col,0);
    //ustreln+2 
    for(int i=0;i<table.size();i++)
        for(int j=0;j<table[i].size();j++)
            for(int k=0;k<table[i][j].size();k++){
                width[j]=max(width[j],ustrlen(table[i][j][k])+2);
            }
    //for(int i=0;i<col;i++)
    //    cout<<width[i]<<endl;
    
    
    //begin to print
    
    //header line
    cout<<ccc[2];
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<width[i];j++)
            cout<<ccc[1];
        if(i==col-1)cout<<ccc[4]<<endl;
        else cout<<ccc[3];
    }
    for(int i=0;i<table.size();i++){
        //how many line this row need
        int ln = 0;
        for(int j=0;j<table[i].size();j++)
            ln = max(ln,(int)table[i][j].size());
        for(int l=0;l<ln;l++){
            cout<<ccc[0];
            for(int j=0;j<table[i].size();j++){
                print_cell(i,j,l,width[j]);
                cout<<ccc[0];
            }
            cout<<endl;
        }
        if(i!=table.size()-1){
            //print middle line  5 6 7
            cout<<ccc[5];
            for(int j=0;j<col;j++)
            {
                for(int k=0;k<width[j];k++)
                    cout<<ccc[1];
                if(j==col-1)cout<<ccc[7]<<endl;
                else cout<<ccc[6];
            }
        }
    }
    
    cout<<ccc[8];
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<width[i];j++)
            cout<<ccc[1];
        if(i==col-1)cout<<ccc[10];
        else cout<<ccc[9];
    }
    return 0;
}
