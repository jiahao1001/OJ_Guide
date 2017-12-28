#include<iostream>
#include<string>
#include<stack>
#include<ctype.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    string term;
    getline(cin,term);
    while(t--){
        getline(cin,term);
        stack<char> left;
        string imm;
        //cout<<term<<endl;
        char op = '+';
        int last='+';
        for(int i=0;i<term.size();i++){
            switch(term[i]){
            case '+':
            case '-':
                op=term[i];
                imm+=term[i];
                break;
            case ' ':
                break;
            case '(':
                if(op=='+'||last=='(') left.push(' ');
                else left.push('('),imm+='(';
                break;
            case ')':
                if(left.top()=='(') imm+=')';
                left.pop();
                break;
            default:
                imm+=term[i];
            }
            last = term[i];
        }
        for(int i=0;i<imm.size();i++){
            if(isalpha(imm[i])){
                int k=1;
                while(i-k>=0 && k+i<imm.size() && imm[i-k]=='(' && imm[i+k]==')'){
                    imm[i-k]=imm[i+k]=' ';
                    k++;
                }
            }
        }
        for(int i=0;i<imm.size();i++)
            if(imm[i]!=' ')cout<<imm[i];
        cout<<endl;
    }
    return 0;
}
