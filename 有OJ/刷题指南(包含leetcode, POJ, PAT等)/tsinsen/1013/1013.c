#include <iostream>
#include<string>
#include <math.h>

using namespace std;

int main(){

    string s;
    cin>>s;

    long long count=0;  //mark

    for(int i=0;i<s.length();i++){
        if(s[i]<='9'){
            count+=(s[i]-'0')*pow(16,s.length()-1-i);
        }else{
            count+=(s[i]-'A'+10)*pow(16,s.length()-1-i);
        }
    }

    cout<<count<<endl;


    return 0;
}