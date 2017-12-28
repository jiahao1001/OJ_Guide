#include <iostream>

using namespace std;

int main(){
    string a,b;
    cin>>a>>b;

    if(a.length()!=b.length()){
        cout<<1<<endl;
        return 0;
    }


    if(a==b){
        cout<<2<<endl;
        return 0;
    }

    for(int i=0;i<a.length();i++){
        if(!(a[i]==b[i]||a[i]+'A'-'a'==b[i]||a[i]-'A'+'a'==b[i])){
            cout<<4<<endl;
            return 0;
        }
    }

    cout<<3<<endl;



    return 0;
}