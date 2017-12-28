#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;
int den[]={9,4,4,4,7};
char c_or_p[5];
int A[5];
//total cal from fat / total cal
void norm(string token,int i){
    int len = token.size();
    int num = atoi(token.substr(0,len-1).c_str());
    if(token[len-1]=='g'){
        A[i] = num*den[i];
        c_or_p[i] = 'c';
    }else if(token[len-1]=='%'){
        A[i] = num;
        c_or_p[i] = 'p';
    }else {
        A[i] = num;
        c_or_p[i] = 'c';
    }
}
int main(){
    
    string token;
    while(cin>>token, token!="-"){
        double t_f=0,t=0;
        do{
            norm(token,0);
            for(int i=1;i<5;i++){
                cin>>token;
                norm(token,i);
            }
            double tp = 100;
            double cc = 0;
            for(int i=0;i<5;i++){
                if(c_or_p[i]=='p') tp-=A[i];
                else cc+=A[i];
            }
            t+= cc*100.0/tp;
            t_f += (c_or_p[0]=='p')?(cc*A[0]/tp):A[0];
            
        }while(cin>>token,token!="-");
        cout<<int(100*t_f/t+0.5)<<"%"<<endl;
    }
    return 0;
}
