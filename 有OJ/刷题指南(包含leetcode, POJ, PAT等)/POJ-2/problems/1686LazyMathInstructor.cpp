#include<iostream>
#include<stdio.h>
#include<string>
#include<ctype.h>
#include<stack>
#include<vector>
using namespace std;
int eval(string line){
    string trimmed = "";
    for(int i=0;i<line.size();i++)
        if(line[i]!=' ' && line[i]!='\t') trimmed += tolower(line[i]);
    vector<char> rpn;
    stack<char> op;
    // maintain strict increase pre
    for(int i=0;i<trimmed.size();i++){
        char &c = trimmed[i];
        if(c=='(') op.push(c);
        else if(c==')'){
            // pop every op until the (
            while(op.top()!='(') rpn.push_back(op.top()),op.pop();
            op.pop();
        }else if(isalpha(c)||isdigit(c)) rpn.push_back(c);
        else{
            while(true){
                if(op.empty()||op.top()=='(' || (c=='*'&&op.top()!='*')) break;
                rpn.push_back(op.top());
                op.pop();
            }
            op.push(c);
        }
    }
    while(!op.empty()) rpn.push_back(op.top()),op.pop();
    stack<int> st;
    for(int i=0;i<rpn.size();i++){
        char &c = rpn[i];
        if(isdigit(c)) st.push(c-'0');
        else if(isalpha(c)) st.push(c-'a'+1);
        else{
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            if(c=='-') st.push(b-a);
            else if(c=='+') st.push(b+a);
            else st.push(a*b);
        }
    }
    //cout<<st.top();
    return st.top();
}
int main()
{
    int t;
    string line;
    string trimmed;
    scanf("%d",&t);
    getline(cin,line);
    while(t--){
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        if(eval(s1)==eval(s2)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
