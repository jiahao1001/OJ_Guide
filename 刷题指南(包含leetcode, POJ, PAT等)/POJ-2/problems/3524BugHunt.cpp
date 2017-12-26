#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctype.h>
using namespace std;
string code;
int it;//the global iterator
int len;
char var;
int num;
struct error {};
struct array{
    int size;
    map<int,int> v;
    array(int n){
        size = n;
    }
    array(){}
    void assign(int i,int val){
        if(i>=size) throw error();
        v[i] = val;
    }
    int get(int i){
        if(i>=size || !v.count(i)) throw error();
        return v[i];
    }
};
map<char,array> env;
bool number(int &x);
bool eat(char c){
    if(it==len) return false;
    if(code[it++]==c) return true;
    it--;
    return false;
}
bool eat_alpha(){
    if(it==len) return false;
    if(isalpha(code[it++])){
        var = code[it-1];
        return true;
    }
    it--;
    return false;
}
bool expr(int &result){
    if(it==len) return false;
    int save = it;
    int n;
    if(number(n)) {
        result = n;
        return true;
    }
    int i;
    char c=code[it];
    if(eat_alpha() && eat('[') && expr(i) && eat(']')) {
        result = env[c].get(i);
        //printf("expr %d\n",result);
        return true;
    }
    it = save;
    return false;
}
bool assignment(){
    if(it==len) return false;
    int save = it;
    int e1,e2;
    char a = code[it];
    if(eat_alpha()
       && eat('[')
       && expr(e1)
       && eat(']')
       && eat('=')
       && expr(e2)
       && eat('\n')) {
        env[a].assign(e1,e2);
        return true;
    }
    it = save;
    return false;
}
bool number(int &xxx){
    if(it==len) return true;
    int save = it;
    int n = 0;
    while(isdigit(code[it]) && it<len) n=n*10+(code[it]-'0'),it++;
    if(it==save) return false;
    num= xxx= n;
    //printf("a number %d\n",n);
    
    return true;
}
bool declaration(){
    if(it==len) return false;
    int save = it;
    int n;
    char var = code[it];
    if(eat_alpha()
       && eat('[')
       && number(n)
       && eat(']')
       && eat('\n')){
        env[var] = array(n);
        return true;
    }
    it = save;
    return false;
}
bool program(){
    int n=1;
    try{
        env.clear();
        while(it<len){
            if(!assignment()) declaration();
            //      cout<<"line "<<n<<endl;
            ++n;
        }
        cout<<"0"<<endl;
    }catch(const error&){
        cout<<n<<endl;
    }
    return true;
}
int main(){
    string line;
    while(getline(cin,line),line!="."){
        code = line+"\n";
        while(getline(cin,line),line!=".")
            code+=line+"\n";
        it=0,len=code.size();
        program();
    }
    return 0;
}
