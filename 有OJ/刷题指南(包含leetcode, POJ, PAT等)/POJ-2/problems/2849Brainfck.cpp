#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<set>
#include<map>
#include<stack>
using namespace std;
const int M = 32768;
const int N = 256;
int mem[M];
int sp,ip;
map<int,int> match;
void add_p(){
    sp++;
    sp %= M;
}
void dec_p(){
    sp--;
    if(sp<0) sp+=M;
}
void add(){
    mem[sp]++;
    mem[sp] %= N;
}
void dec(){
    mem[sp]--;
    if(mem[sp]<0) mem[sp]+=N;
}
void output(){
    cout<<(char)mem[sp];
}
void jump_f(){
    if(!mem[sp]) ip = match[ip];
}
void jump_b(){
    if(mem[sp]) ip = match[ip]-1;
}
int main()
{
    int t;
    cin>>t;
    string v = "<>+-.[]";
    for(int q=1;q<=t;q++){
        string prog = "";
        string line;
        sp = 0;
        match.clear();
        memset(mem, 0, sizeof mem);
        while(getline(cin,line),line!="end"){
            for(int i=0;i<line.size();i++){
                if(line[i]=='%') break;
                if(v.find_first_of(line[i])==string::npos) continue;
                prog += line[i];
            }
        }
        //cout<<prog<<endl;
        
        bool ok = true;
        stack<int> st;
        for(int i=0;i<prog.size();i++){
            if(prog[i]=='[') st.push(i);
            else if(prog[i]==']'){
                if(st.empty()){
                    ok = false;
                    break;
                }
                int p = st.top();
                st.pop();
                match[p] = i;
                match[i] = p;
            }
        }
        if(!st.empty()) ok = false;
        cout<<"PROGRAM #"<<q<<":"<<endl;
        if(!ok){
            cout<<"COMPILE ERROR"<<endl;
            continue;
        }
        for(ip=0;ip<prog.size();ip++){
            switch(prog[ip]){
            case '>':
                add_p();
                break;
            case '<':
                dec_p();
                break;
            case '+':
                add();
                break;
            case '-':
                dec();
                break;
            case '.':
                output();
                break;
            case '[':
                jump_f();
                break;
            case ']':
                jump_b();
                break;
            }
        }
        cout<<endl;
    }
    return 0;
}
