#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
string header,hh;
vector<string> row;
vector<int> len;
inline void display(char a,string token,int l){
    int sz = token.size();
    int left =0, right = 0;
    if(a=='='){
        left = (l-sz)/2;
        right = l-sz-left;
    }else if(a=='<'){
        left = 1;
        right = l-sz-left;
    }else{
        right = 1;
        left = l-sz-right;
    }
    for(int i=0;i<left;i++)
        printf(" ");
    printf("%s",token.c_str());
    for(int i=0;i<right;i++)
        printf(" ");
    printf("|");
}
int main(){
    getline(cin,header);
    while(header!="*"){
        row.clear();
        len.clear();
        for(int i=0;i<header.size();i++) len.push_back(0);
        string line;
        while(getline(cin,line)){
            if(line[0]=='>' || line[0]=='=' || line[0]=='<' || line[0]=='*'){
                hh = header;
                header = line;
                break;
            }
            istringstream is(line);
            string token;
            for(int i=0;i<len.size();i++){
                getline(is,token,'&');
                len[i] = max(len[i],(int)(token.size())+2);
            }
            row.push_back(line);
        }
        
        int tot = 0;
        for(int i=0;i<len.size();i++) tot += len[i];
        printf("@");
        for(int i=0;i<tot+len.size()-1;i++)
            printf("-");
        printf("@\n");
        for(int i=0;i<row.size();i++){
            string line = row[i];
            istringstream is(line);
            string token;
            printf("|");
            for(int j=0;j<len.size();j++){
                getline(is,token,'&');
                display(hh[j],token,len[j]);
            }
            printf("\n");
            if(i==0){
                printf("|");
                for(int j=0;j<len.size();j++){
                    for(int k=0;k<len[j];k++) printf("-");
                    if(j!=len.size()-1)printf("+");
                }
                printf("|\n");
            }
        }
        printf("@");
        for(int i=0;i<tot+len.size()-1;i++)
            printf("-");
        printf("@\n");
    }
    return 0;
}
