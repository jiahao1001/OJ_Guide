#include <iostream>

using namespace std;

void get_divisor(int n){
    int b=n;
    cout<<b<<"=";

    for(int i=2;i*i<=b;i++){
        while(b%i==0){
            b=b/i;
            if(1==b){
                cout<<i<<endl;
            }else {
                cout<<i<<"*";
            }
        }
    }

    if(b>1){
        cout<<b<<endl;
    }

}

int main(){

    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        get_divisor(i);
    }

    return 0;
}